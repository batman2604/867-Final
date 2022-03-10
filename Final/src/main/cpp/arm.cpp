#include "Robot.h"

TalonSRX A1 = {9};
TalonSRX A2 = {8};
TalonSRX A3 = {10};
TalonSRX A4 = {7};
Pigeon2 pig{0};

int limit1 = 0;
int limit2 = 0;


Pigeon2Configuration con;

void aSetup(){
    A1.SetNeutralMode(Brake);
    A2.SetNeutralMode(Brake);
    A3.SetNeutralMode(Brake);
    A4.SetNeutralMode(Brake);
    A1.SetInverted(true);
    A3.SetInverted(true);
}
void pSetup(){
    con.MountPosePitch = -90;
    con.MountPoseRoll = -180;
    con.MountPoseYaw = 0;
    pig.ConfigAllSettings(con);
}

void set_arm_1(double input){
    A1.Set(ControlMode::PercentOutput, input);
    A4.Set(ControlMode::PercentOutput, input);
}

void set_arm_2(double input){
    A2.Set(ControlMode::PercentOutput, input);
    A3.Set(ControlMode::PercentOutput, input);
}

void arm_control(){
    /*
    if(limit1 >= 0){
    if(control.GetRawButton(4) ==  true){
        set_arm_1(0.5);
        limit1 +=1;
    }
    else if (control.GetRawButton(1)==true){
        set_arm_1(-0.5);
        limit1 -= 1;
    }
    else {
        set_arm_1(0);
    }
    }
     else {
        set_arm_1(0);
        std::this_thread::sleep_for(50ms);
        while(limit1 < 0){
        set_arm_1(1);
        limit1 += 1;
        }
    }
    */
    if(control.GetRawButton(4) ==  true){
        set_arm_1(0.5);
        
    }
    else if (control.GetRawButton(1)==true){
        set_arm_1(-0.5);
        
    }
    else {
        set_arm_1(0);
    }
    if(control.GetRawButton(2) ==  true){
        set_arm_2(1);
    }
    else if (control.GetRawButton(3)==true){
        set_arm_2(-1);
    }
    else {
        set_arm_2(0);
    }
    
   /*
    if(limit2 >= 0){
    if(control.GetRawButton(3) ==  true){
        set_arm_2(0.5);
        limit2 +=1;
    }
    else if (control.GetRawButton(2)==true){
        set_arm_2(-0.5);
        limit2 -= 1;
    }
    else {
        set_arm_2(0);
    }
    }
     else {
        set_arm_2(0);
        std::this_thread::sleep_for(50ms);
        while(limit2 < 0){
        set_arm_2(1);
        limit2 += 1;
        }
    }
    */
}