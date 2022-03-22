#include "main.h"

RamseteController::RamseteController(double beta, double zeta) {
    this->beta = beta;
    this->zeta = zeta;
}

RamseteController::RamseteController() {
    beta = 2.0;
    zeta = 0.7;
}

std::pair<double, double> RamseteController::update(double currX, double currY, double currTheta, 
                                            double desiredX, double desiredY, double desiredTheta, 
                                            double linearVelocityRefMeters, 
                                            double angularVelocityRefRadiansPerSecond) 
{
    double eX = desiredX - currX;
    double eY = desiredY - currY;
    double eTheta = desiredTheta - currTheta;
    double vRef = linearVelocityRefMeters;
    double omegaRef = angularVelocityRefRadiansPerSecond;

    double k = 2.0 * zeta * std::sqrt(std::pow(omegaRef, 2) + beta * std::pow(vRef, 2));

    return std::make_pair(vRef * std::cos(eTheta) + k * eX, 
                          omegaRef + k * eTheta + beta * vRef * sinc(eTheta) * eY);
}

double RamseteController::sinc(double x) {
    if (std::abs(x) < 1e-9) {
        return 1.0 - 1.0 / 6.0 * x * x;
    } else {
        return std::sin(x) / x;
    }
}