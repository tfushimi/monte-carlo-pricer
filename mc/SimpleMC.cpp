#include "SimpleMC.hpp"
#include "Random.hpp"
#include "VanillaOption.hpp"
#include "Parameter.hpp"
#include "MCStatistics.hpp"
#include <cmath>
#include <iostream>
#include <valarray>

void simpleMC(const VanillaOption& option,
              double spot,
              Parameter vol,
              Parameter rate,
              unsigned long numberOfPaths,
              MCStatistics& mcStatistics,
              RandomBase& generator) {
    generator.reset();
    double expiration = option.getExpiry();
    double variance = vol.integralSquare(0.0, expiration);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;

    double movedSpot = spot * exp(rate.integral(0.0, expiration) + itoCorrection);
    double thisSpot;
    double discountFactor = exp(-rate.integral(0.0, expiration));
    
    std::valarray<double> variate(1);
    
    for (unsigned long i = 0; i < numberOfPaths; i++) {
        generator.getGaussians(variate);
        thisSpot = movedSpot * exp(rootVariance * variate[0]);
        double thisPayOff = option.calcPayOff(thisSpot);
        mcStatistics.dumpOneResult(thisPayOff * discountFactor);
    }
}
