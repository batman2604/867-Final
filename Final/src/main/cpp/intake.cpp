#include "Robot.h"

TalonSRX intake = {11};

void iSetup(){
    intake.SetNeutralMode(Brake);
}
void set_intake(double input){
    intake.Set(ControlMode::PercentOutput, input);
}

void intake_control(){
   if(control.GetRawButton(5) == true){
       set_intake(1);
   }
   else if (control.GetRawButton(6) == true){
       set_intake(-1);
   }
   else {
       set_intake(0);
   }
}