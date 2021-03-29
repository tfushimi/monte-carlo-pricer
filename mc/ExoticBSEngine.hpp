#ifndef ExoticBSEngine_hpp
#define ExoticBSEngine_hpp

#include "ExoticEngine.hpp"
#include "Random.hpp"

class ExoticBSEngine: public ExoticEngine {
public:
    ExoticBSEngine(const Wrapper<PathDependentOption>& option,
                   const Parameter& rate,
                   const Parameter& dividend,
                   const Parameter& vol,
                   const Wrapper<RandomBase>& generator,
                   double spot);
    virtual void getOnePath(std::valarray<double>& spotPrices);
    virtual ~ExoticBSEngine(){}
    
private:
    Wrapper<RandomBase> generator;
    std::valarray<double> drifts;
    std::valarray<double> vols;
    double logSpot;
    unsigned long numberOfTimes;
    std::valarray<double> variates;
};
#endif