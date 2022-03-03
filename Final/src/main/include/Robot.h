// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

//Libraries
#include <frc/TimedRobot.h>
#include <ctre/Phoenix.h> //Motor Library
#include <frc/Joystick.h>
#include <wpi/future.h>
#include <chrono>
#include <frc/BuiltInAccelerometer.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Timer.h>
#include <thread>
#include <iostream>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"
#include "wpi/span.h"

using namespace std::literals::chrono_literals;
using namespace std;
#define ENCROT 4096

//Header Files
#include "drive.hpp"
#include "intake.hpp"
#include "shooter.hpp"
#include "arm.hpp"


class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

  void SimulationInit() override;
  void SimulationPeriodic() override;
};
