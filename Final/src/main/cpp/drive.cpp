#include "Robot.h"

//Motors
TalonSRX L1 = {1};
TalonSRX L2 = {2};
TalonSRX R1 = {3};
TalonSRX R2 = {4};
frc::Joystick control(0);

void dSetup(){
    L1.SetNeutralMode(Brake);
    L2.SetNeutralMode(Brake);
    R1.SetNeutralMode(Brake);
    R2.SetNeutralMode(Brake);
    R2.SetInverted(true);
    L2.SetInverted(true);
    R2.ConfigSelectedFeedbackSensor(TalonSRXFeedbackDevice::CTRE_MagEncoder_Relative, 0, 10);
}

void drive(double l_input, double r_input){
    L1.Set(ControlMode::PercentOutput, l_input);
    L2.Set(ControlMode::PercentOutput, l_input);
    R1.Set(ControlMode::PercentOutput, r_input);
    R2.Set(ControlMode::PercentOutput, r_input);
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