#include "ExoticBSEngine.hpp"
#include <cmath>

void ExoticBSEngine::getOnePath(std::valarray<double> &spotPrices) {
    generator->getGaussians(variates);
    double currentLogSpot = logSpot;
    
    for (unsigned long j=0; j < numberOfTimes; j++) {
        currentLogSpot += drifts[j];
        currentLogSpot += vols[j] * variates[j];
        spotPrices[j] = exp(currentLogSpot);
    }
}

ExoticBSEngine::ExoticBSEngine(const Wrapper<PathDependentOption>& option,
                               const Parameter& rate,
                               const Parameter& dividend,
                               const Parameter& vol,
                               const Wrapper<RandomBase>& generator_,
                               double spot): ExoticEngine(option, rate), generator(generator_) {
    std::valarray<double> times(option->getLookAtTimes());
    numberOfTimes = times.size();
    
    generator->resetDimension(numberOfTimes);
    drifts.resize(numberOfTimes);
    vols.resize(numberOfTimes);
    
    double variance = vol.integralSquare(0.0, times[0]);
    
    drifts[0] = rate.integral(0.0, times[0]) - dividend.integral(0.0, times[0]) - 0.5 * variance;
    vols[0] = sqrt(variance);
    
    for (unsigned long j = 1; j < numberOfTimes; j++) {
        double thisVariance = vol.integralSquare(times[j-1], times[j]);
        drifts[j] = rate.integral(times[j-1], times[j]) - dividend.integral(times[j-1], times[j]) - 0.5 * thisVariance;
        vols[j] = sqrt(thisVariance);
    }
    
    logSpot = log(spot);
    variates.resize(numberOfTimes);
}
