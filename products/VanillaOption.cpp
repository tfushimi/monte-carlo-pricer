#include "VanillaOption.hpp"
#include "PayOff.hpp"

VanillaOption::VanillaOption(const PayOffBridge& payoff,
                             double expiration
                             ): expiration(expiration), payOff(payoff) {
    
}

double VanillaOption::getExpiry() const {
    return expiration;
}

double VanillaOption::calcPayOff(double spot) const {
    return payOff(spot);
}
