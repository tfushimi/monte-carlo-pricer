#include "ExoticEngine.hpp"
#include "Wrapper.hpp"
#include <cmath>

ExoticEngine::ExoticEngine(const Wrapper<PathDependentOption>& option, const Parameter& rate): option(option), rate(rate), discountFactors(option->possibleCashFlowTimes()) {
    // i dont like storin times in and overwrite it with discount factor
    for (unsigned long i=0; i < discountFactors.size(); i++) {
        discountFactors[i] = exp(-rate.integral(0.0, discountFactors[i]));
    }
    cashFlows.resize(option->maxNumberOfCashFlows());
}

void ExoticEngine::doSimulation(MCStatistics &gatherer, unsigned long numberOfPaths) {
    std::valarray<double> spotPrices(option->getLookAtTimes().size());
    
    cashFlows.resize(option->maxNumberOfCashFlows());
    double thisValue;
    
    for (unsigned long i=0; i < numberOfPaths; i++) {
        getOnePath(spotPrices);
        thisValue = doOnePath(spotPrices);
        gatherer.dumpOneResult(thisValue);
    }
}

double ExoticEngine::doOnePath(const std::valarray<double> &spotPrices) const {
    unsigned long numberFlows = option->CashFlows(spotPrices, cashFlows);
    double value = 0.0;
    for (unsigned i = 0; i < numberFlows; i++) {
        value += cashFlows[i].amount * discountFactors[cashFlows[i].timeIndex];
    }
    return value;
}
