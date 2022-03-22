#pragma once

class FeedForwardController {
    private: 
    double kV, kA_Up, kA_Down, kP_Pos, kP_Vel;
    double currPos, currVel, power;

    public: 
    FeedForwardController(double ikV, double ikAU, double ikAD, double ikP_Pos, double ikP_Vel);
    double step(double position, double velocity, double acceleration, double currentPos, double currentRPM);
};