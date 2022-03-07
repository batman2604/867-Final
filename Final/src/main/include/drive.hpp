#ifndef DRIVEH
    #define DRIVEH
        
        // Limelight constants
        #define LIMELIGHT_ANGLE 30 // in degrees
        #define TARGET_HEIGHT 104 // inches 
        #define LIMELIGHT_HEIGHT 12 // inches
        #define PI 3.14159265

        // Encoder constants
        #define ENCROT 4096 //Full rotation in Encoder Units

        extern  frc::Joystick control;
        double getTargetHorizontalDistance(); // Limelight-measured distance
        void dSetup();
        void autoMain(int target);
        void turn(int degree);
        void drive(double l_input, double r_input);




#endif
