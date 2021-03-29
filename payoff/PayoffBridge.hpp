#ifndef PayoffBridge_hpp
#define PayoffBridge_hpp

#include "PayOff.hpp"

/*
 This class solely provides memory management functionality.
    - copy constructor
    - assignment operator
    - destructor
 
 In addition, it provides a constructor from PayOff, so that implicit conversion from PayOff
 to PayOffBridge is supported.
 */
class PayOffBridge {
public:
    PayOffBridge(const PayOffBridge& original);
    PayOffBridge(const PayOff& payoff);
    
    inline double operator()(double spot) const;
    ~PayOffBridge();
    PayOffBridge& operator=(const PayOffBridge& original);
    
private:
    PayOff* payOffPtr;
};

inline double PayOffBridge::operator()(double spot) const {
    return payOffPtr->operator()(spot);
}
#endif 
