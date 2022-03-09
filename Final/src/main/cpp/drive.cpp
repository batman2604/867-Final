#include "Robot.h"
#include <math.h>>

//Motors
TalonSRX L1 = {1};
TalonSRX L2 = {2};
TalonSRX R1 = {3};
TalonSRX R2 = {4};
frc::Joystick control(0);

//std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
//double targetOffsetAngle_Horizontal = table->GetNumber("tx",0.0);

double prevThrot_l;
double prevThrot_r;

// Limelight distance measurement
// C++ tan takes radians as argument, atan returns radians
// limelight table is in degrees --> need to convert to radians
double getTargetHorizontalDistance() {
	auto inst = nt::NetworkTableInstance::GetDefault();
	auto table = inst.GetTable("limelight");
	//std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
	double targetOffsetAngle_Vertical = table->GetNumber("tx",0.0);
	double targetAngle = (targetOffsetAngle_Vertical + LIMELIGHT_ANGLE) * PI / 180; // radians
	double targetHorizontalDistance = (TARGET_HEIGHT - LIMELIGHT_HEIGHT) / tan(targetAngle);
	return targetHorizontalDistance;
}

// Used to angle to robot towards the target. When this returns 0 we are ready to shoot.
double getXOffset() {
    auto inst = nt::NetworkTableInstance::GetDefault();
	auto table = inst.GetTable("limelight");
    double targetOffsetAngle_Horizontal = table->GetNumber("ty",0.0); // degrees
    double angle_diff = atan(LENS_TO_SHOOTER_DIST/getTargetHorizontalDistance()) * 180 / PI; // degrees
    return targetOffsetAngle_Horizontal - angle_diff; // what the angle would be if limelight were centered
}

void repositionToShoot() {
    while (getXOffset()>0.1) turn(1);
    while (getXOffset()<0.1) turn(-1);
    // Shooter is now pointing towards hoop, go to right radius
    double dist = getTargetHorizontalDistance(); 
    while (dist>DISTANCE_TO_SHOOT_FROM+0.1) {
        autoMain(dist-DISTANCE_TO_SHOOT_FROM);
        dist = getTargetHorizontalDistance(); 
    }
    while (dist<DISTANCE_TO_SHOOT_FROM-0.1) {
        autoMain(DISTANCE_TO_SHOOT_FROM-dist);
        dist = getTargetHorizontalDistance(); 
    }
}

void dSetup(){
    L1.SetNeutralMode(Brake);
    L2.SetNeutralMode(Coast);
    R1.SetNeutralMode(Brake);
    R2.SetNeutralMode(Coast);
    L2.SetInverted(true);
    L1.SetInverted(true);
    R2.ConfigSelectedFeedbackSensor(TalonSRXFeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
}

void drive(double l_input, double r_input){
    /*
    if((abs(l_input)/abs(prevThrot_l) >1.4) && (abs(l_input) > 0.7)){
       l_input = (l_input * 0.8);
   } else
   if((abs(r_input)/abs(prevThrot_r) >1.4) && (abs(r_input) > 0.7)){
       r_input = (r_input * 0.8);
   }
   */
    L1.Set(ControlMode::PercentOutput, l_input);
    L2.Set(ControlMode::PercentOutput, l_input);
    R1.Set(ControlMode::PercentOutput, r_input);
    R2.Set(ControlMode::PercentOutput, r_input);
   prevThrot_l = l_input;
   prevThrot_r = r_input;                       
   std::this_thread::sleep_for(50ms);                               
}


//PID Values SetUp
float kP = 0.0015;
float kI;
float kD;
int pos;

//Main Auto PID DRIVE
void autoMain(int target){
    target = target * ENCROT;
    int error, prevError, deriv;
    float power;
    R2.SetSelectedSensorPosition(0, 0, 10);
    pos = R2.GetSelectedSensorPosition(0);
    while(abs(pos) < abs(target)){
        deriv = error - prevError;
        prevError = error;
        error = target - pos; 
        power = (kP * error) + (deriv * kD);
        drive(power, power);
        pos = R2.GetSelectedSensorPosition(0);
        std::this_thread::sleep_for(10ms);
    }
    std::this_thread::sleep_for(40ms);

}

//Main Auto PID Turn
void turn(int degree){
    float rot = (5.5 * degree)/180;
    int error, prevError, deriv;
    float power;
    R2.SetSelectedSensorPosition(0, 0, 10);
    pos = R2.GetSelectedSensorPosition(0);
    while(abs(pos) < abs(rot)){
        deriv = error - prevError;
        prevError = error;
        error = rot - pos; 
        power = (kP * error) + (deriv * kD);
        drive(power, power);
        pos = R2.GetSelectedSensorPosition(0);
        std::this_thread::sleep_for(10ms);
    }
    std::this_thread::sleep_for(40ms);

}
