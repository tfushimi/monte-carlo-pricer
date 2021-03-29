#ifndef AsianOption_hpp
#define AsianOption_hpp

#include "PathDependentOption.hpp"
#include "PayoffBridge.hpp"

class AsianOption: public PathDependentOption {
public:
    AsianOption(const std::valarray<double>& lookAtTimes,
                double maturityTime,
                const PayOffBridge& payoff);
    
    virtual unsigned long maxNumberOfCashFlows() const;
    virtual std::valarray<double> possibleCashFlowTimes() const;
    virtual unsigned long CashFlows(const std::valarray<double>& spotPrices,
                                    std::vector<CashFlow>& generatedFlows) const;
    virtual ~AsianOption(){}
    virtual PathDependentOption* clone() const;
    
private:
    double maturityTime;
    PayOffBridge payoff;
    unsigned long numberOfTimes;
};
#endif