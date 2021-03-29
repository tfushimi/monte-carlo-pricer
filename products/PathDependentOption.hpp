#ifndef PathDependentOption_hpp
#define PathDependentOption_hpp

#include <vector>
#include <valarray>

class CashFlow {
public:
    double amount;
    unsigned long timeIndex;
    
    CashFlow(unsigned long timeIndex=0UL, double amount=0.0): timeIndex(timeIndex), amount(amount){};
};

class PathDependentOption {
public:
    PathDependentOption(const std::valarray<double>& lookAtTimes);
    
    const std::valarray<double>& getLookAtTimes() const;
    
    virtual unsigned long maxNumberOfCashFlows() const=0;
    virtual std::valarray<double> possibleCashFlowTimes() const=0;
    virtual unsigned long CashFlows(const std::valarray<double>& spotPrices, std::vector<CashFlow>& generatedFlows) const=0;
    virtual PathDependentOption* clone() const=0;
    virtual ~PathDependentOption(){}
    
private:
    std::valarray<double> lookAtTimes;
};
#endif
