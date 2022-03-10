#include "Robot.h"

TalonSRX S1 = {6};
TalonSRX S2 = {5};
TalonSRX indexroll = {12};
bool onp = false;

void shotSetup(){
    S1.SetNeutralMode(Brake);
    S2.SetNeutralMode(Brake);
    //S2.SetInverted(true);
    indexroll.SetNeutralMode(Brake);    
}
void set_index(int input){
    indexroll.Set(ControlMode::PercentOutput, input);
}

void set_shooter(double input){
    S1.Set(ControlMode::PercentOutput, input);
    S2.Set(ControlMode::PercentOutput, input);
}

void shooter_control(){
    set_shooter(control.GetRawAxis(3));
    set_index(control.GetRawAxis(2));
    std::cout << control.GetRawAxis(3) << std::endl;
}