#ifndef VanillaOption_hpp
#define VanillaOption_hpp

#include "PayoffBridge.hpp"
#include "PayOff.hpp"

class VanillaOption {
public:
    VanillaOption(const PayOffBridge& payoff, double expiration);
    
    double getExpiry() const;
    double calcPayOff(double spot) const;
    
private:
    double expiration;
    PayOffBridge payOff;
};

#endif