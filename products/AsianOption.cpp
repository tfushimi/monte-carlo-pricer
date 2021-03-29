#include "AsianOption.hpp"

AsianOption::AsianOption(const std::valarray<double>& lookAtTimes,
                         double maturityTime,
                         const PayOffBridge& payoff): PathDependentOption(lookAtTimes), maturityTime(maturityTime), payoff(payoff), numberOfTimes(lookAtTimes.size()) {
    
}

unsigned long AsianOption::maxNumberOfCashFlows() const {
    return 1UL;
}

std::valarray<double> AsianOption::possibleCashFlowTimes() const {
    std::valarray<double> temp(1UL);
    temp[0] = maturityTime;
    return temp;
}

unsigned long AsianOption::CashFlows(const std::valarray<double> &spotPrices,
                                     std::vector<CashFlow> &generatedFlows) const {
    double sum = spotPrices.sum();
    double mean = sum / numberOfTimes;
    generatedFlows[0].timeIndex = 0UL;
    generatedFlows[0].amount = payoff(mean);
    
    return 1UL;
}

PathDependentOption* AsianOption::clone() const {
    return new AsianOption(*this);
}
