// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

using namespace std::literals::chrono_literals;
using namespace std;
#define ENCROT 4096

// TalonSRX Climber = {2};
// TalonSRX Launcher1 = {3};
// TalonSRX Launcher2 = {4};






// void Launcher(){
//   if(control.GetRawButton(5)==true){
//     Launcher1.Set(ControlMode::PercentOutput, 1);
//     Launcher2.Set(ControlMode::PercentOutput, 1);
//     //wpi::future <double> wait_until(std::chrono::time_point<std::chrono::steady_clock, std::chrono::seconds> & 30);
//    // wpi::future <double> wait_for(std::chrono::seconds<)

//   }
//   else if (control.GetRawButton(6)==true){
//     Launcher1.Set(ControlMode::Current, 30);
//   }
//   else {
//     Launcher1.Set(ControlMode::PercentOutput, 0);
//     Launcher2.Set(ControlMode::PercentOutput, 0);
//   }
// }

void Robot::RobotInit() {

}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() 
{

}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {
  set_intake(1);
  autoMain(8);
  set_intake(0);
  turn(-13);
  set_shooter(1);
  std::this_thread::sleep_for(1000ms);
  set_shooter(0);
  turn(6);
  set_intake(1);
  autoMain(7);
  set_intake(0);
}
void Robot::TestPeriodic() {
  while(true){
  drive(control.GetRawAxis(7), control.GetRawAxis(4));
  intake_control();
  shooter_control();
  }
}
void Robot::SimulationInit() {}
void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
