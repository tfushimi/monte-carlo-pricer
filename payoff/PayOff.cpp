#include "PayOff.hpp"
#include <algorithm>

PayOffCall::PayOffCall(double strike): strike(strike) {
    
}

double PayOffCall::operator()(double spot) const {
    return std::max(spot - strike, 0.0);
}

PayOff* PayOffCall::clone() const {
    return new PayOffCall(*this);
}

PayOffPut::PayOffPut(double strike): strike(strike) {
    
}

double PayOffPut::operator()(double spot) const {
    return std::max(strike - spot, 0.0);
}

PayOff* PayOffPut::clone() const {
    return new PayOffPut(*this);
}
