// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"





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
  /*
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
  */
 shotSetup();
 dSetup();
}
void Robot::TestPeriodic() {

  drive(control.GetRawAxis(1), control.GetRawAxis(5));
  intake_control();
  //shooter_control();
  //arm_control();
  
}
void Robot::SimulationInit() {}
void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
