#ifndef DRIVEH
    #define DRIVEH

        #define ENCROT 4096 //Full rotation in Encoder Units
        extern  frc::Joystick control;
        void dSetup();
        void autoMain(int target);
        void turn(int degree);
        void drive(float l_input, float r_input);




#endif