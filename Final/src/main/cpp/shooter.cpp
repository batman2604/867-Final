#include "Robot.h"

TalonSRX S1 = {6};
TalonSRX S2 = {7};
TalonSRX S3 = {8};
TalonSRX S4 = {9};
TalonSRX indexroll = {10};

void shotSetup(){
    S1.SetNeutralMode(Brake);
    S2.SetNeutralMode(Brake);
    S3.SetNeutralMode(Brake);
    S4.SetNeutralMode(Brake);
    indexroll.SetNeutralMode(Brake);    
}




void set_shooter(int input){
    S1.Set(ControlMode::PercentOutput, input);
    S2.Set(ControlMode::PercentOutput, input);
    S3.Set(ControlMode::PercentOutput, input);
    S4.Set(ControlMode::PercentOutput, input);
    if(input != 0){
    std::this_thread::sleep_for(50ms);
    indexroll.Set(ControlMode::PercentOutput, input);
    }
    else {
        indexroll.Set(ControlMode::PercentOutput, input);
    }
}

void shooter_control(){
    if(control.GetRawAxis(5) == -1){
        set_shooter(1);
    }
    else{
        set_shooter(0);
    }
}