#pragma once
#include <utility>

class RamseteController {
    private:
    double beta, zeta;

    public:
    RamseteController();
    RamseteController(double beta, double zeta);
    std::pair<double, double> update(double currX, double currY, double currTheta, 
                                     double desiredX, double desiredY, double desiredTheta, 
                                     double linearVelocityRefMeters, 
                                     double angularVelocityRefRadiansPerSecond);
    std::pair<double, double> update(double currX, double currY, double currTheta, 
                                     double desiredX, double desiredY, double desiredTheta);
    double sinc(double x);
};