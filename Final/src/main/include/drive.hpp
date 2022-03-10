#ifndef DRIVEH
    #define DRIVEH
        
        // Limelight constants
        #define LIMELIGHT_ANGLE 55 // in degrees
        #define TARGET_HEIGHT 104 // inches 
        #define LIMELIGHT_HEIGHT 20 // inches
        #define DISTANCE_TO_SHOOT_FROM 80 // inches
        #define LENS_TO_SHOOTER_DIST 5.75 // inches
        #define PI 3.14159265

        // Encoder constants
        #define ENCROT 4096 //Full rotation in Encoder Units

        extern  frc::Joystick control;
        extern frc::Joystick movein;
        double getTargetHorizontalDistance(); // Limelight-measured distance
        double getXOffset();
        void repositionToShoot();
        void dSetup();
        void autoMain(int target);
        void turn(int degree);
        void drive(double l_input, double r_input);
        void tank(double l_input, double r_input);



#endif
