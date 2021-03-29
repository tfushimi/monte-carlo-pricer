#ifndef ConvergenceTable_hpp
#define ConvergenceTable_hpp

#include "MCStatistics.hpp"
#include "Wrapper.hpp"
#include <vector>

class ConvergenceTable : public MCStatistics {
public:
    ConvergenceTable(const Wrapper<MCStatistics>& innerMCStatistics);
    
    virtual MCStatistics* clone() const;
    virtual void dumpOneResult(double result);
    virtual std::vector<std::vector<double>> getResultsSoFar() const;
    
private:
    Wrapper<MCStatistics> innerMCStatistics;
    std::vector<std::vector<double>> resultsSoFar;
    unsigned long stoppingPoint;
    unsigned long pathsDone;
};
#endif
