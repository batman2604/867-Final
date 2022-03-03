#include "Robot.h"

TalonSRX S1 = {6};
TalonSRX S2 = {7};
//TalonSRX indexroll = {10};


void shotSetup(){
    S1.SetNeutralMode(Brake);
    S2.SetNeutralMode(Brake);
    //S2.SetInverted(true);
    //indexroll.SetNeutralMode(Brake);    
}

void set_shooter(int input){
    S1.Set(ControlMode::PercentOutput, input);
    S2.Set(ControlMode::PercentOutput, input);
    // if(input != 0){
    // std::this_thread::sleep_for(50ms);
    // indexroll.Set(ControlMode::PercentOutput, input);
    // }
    // else {
    //     indexroll.Set(ControlMode::PercentOutput, input);
    // }
}

void shooter_control(){
    if(control.GetRawButton(3) == true){
        set_shooter(1);
    }
    else{
        set_shooter(0);
    }
}