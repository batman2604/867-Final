#include "Robot.h"

TalonSRX intake = {11};

void iSetup(){
    intake.SetNeutralMode(Brake);
}
void set_intake(double input){
    intake.Set(ControlMode::PercentOutput, input);
}

void intake_control(){
   set_intake(control.GetRawAxis(3));
}