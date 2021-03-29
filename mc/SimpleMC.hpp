#ifndef SimpleMC_hpp
#define SimpleMC_hpp

#include "VanillaOption.hpp"
#include "Parameter.hpp"
#include "Random.hpp"
#include "MCStatistics.hpp"

void simpleMC(const VanillaOption& option,
              double spot,
              Parameter vol,
              Parameter rate,
              unsigned long numberOfPaths,
              MCStatistics& mcStatistics,
              RandomBase& generator);

#endif