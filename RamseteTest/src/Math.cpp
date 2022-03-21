#include "main.h"

double Math::tickToFt(double ticks){
    return (ticks/300)*(3.0/5)*(3.25*M_PI)/12;
}

double Math::rpmToFtps(double rpm) {
    return rpm / 60 * (3.0/5) * (3.25 * M_PI) / 12;
}