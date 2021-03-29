#include "PathDependentOption.hpp"

PathDependentOption::PathDependentOption(const std::valarray<double>& lookAtTimes): lookAtTimes(lookAtTimes) {
    
}

const std::valarray<double>& PathDependentOption::getLookAtTimes() const {
    return lookAtTimes;
}
