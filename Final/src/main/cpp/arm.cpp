#include "Robot.h"

TalonSRX A1 = {9};
TalonSRX A2 = {8};

void aSetup(){
    A1.SetNeutralMode(Brake);
    A2.SetNeutralMode(Brake);
}

void set_arm_R(double input){
    A1.Set(ControlMode::PercentOutput, input);
}

void set_arm_L(double input){
    A2.Set(ControlMode::PercentOutput, input);
}

void arm_control(){
    set_arm_L(control.GetRawAxis(6));
    if(control.GetRawButton(4) ==  true){
        set_arm_R(1);
    }
    else if (control.GetRawButton(1)==true){
        set_arm_R(-1);
    }
    else {
        set_arm_R(0);
    }
}