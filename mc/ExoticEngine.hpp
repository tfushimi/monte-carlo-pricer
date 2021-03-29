#ifndef ExoticEngine_hpp
#define ExoticEngine_hpp

#include "Wrapper.hpp"
#include "Parameter.hpp"
#include "PathDependentOption.hpp"
#include "MCStatistics.hpp"
#include <vector>

class ExoticEngine {
public:
    ExoticEngine(const Wrapper<PathDependentOption>& option, const Parameter& rate);
    
    virtual void getOnePath(std::valarray<double>& spotPrices)=0;
    void doSimulation(MCStatistics& gatherer, unsigned long numberOfPaths);
    virtual ~ExoticEngine(){}
    double doOnePath(const std::valarray<double>& spotPrices) const;
    
private:
    Wrapper<PathDependentOption> option;
    Parameter rate;
    std::valarray<double> discountFactors;
    mutable std::vector<CashFlow> cashFlows;
};

#endif