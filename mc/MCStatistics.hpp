#ifndef MCStatistics_hpp
#define MCStatistics_hpp

#include <vector>

// abstract base class
class MCStatistics {
public:
    MCStatistics(){}
    
    virtual void dumpOneResult(double result)=0;
    virtual std::vector<std::vector<double>> getResultsSoFar() const=0;
    virtual MCStatistics* clone() const = 0;
    virtual ~MCStatistics(){}
};

class MCStatisticsMean: public MCStatistics {
public:
    MCStatisticsMean();
    virtual void dumpOneResult(double result);
    virtual std::vector<std::vector<double>> getResultsSoFar() const;
    virtual MCStatistics* clone() const;
    
private:
    double runningSum;
    unsigned long pathsDone;
};
#endif