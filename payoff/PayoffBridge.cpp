#include "PayoffBridge.hpp"

PayOffBridge::PayOffBridge(const PayOffBridge& original) {
    payOffPtr = original.payOffPtr->clone();
}

PayOffBridge::PayOffBridge(const PayOff& payoff) {
    payOffPtr = payoff.clone();
}

PayOffBridge::~PayOffBridge() {
    delete payOffPtr;
}

PayOffBridge& PayOffBridge::operator=(const PayOffBridge& original) {
    if (this != &original) {
        delete payOffPtr;
        payOffPtr = original.payOffPtr->clone();
    }
    return *this;
}
