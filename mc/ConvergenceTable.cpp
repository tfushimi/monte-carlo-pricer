#include "ConvergenceTable.hpp"

ConvergenceTable::ConvergenceTable(const Wrapper<MCStatistics>& innerMCStatistics): innerMCStatistics(innerMCStatistics) {
    stoppingPoint = 2;
    pathsDone = 0;
}

MCStatistics* ConvergenceTable::clone() const {
    return new ConvergenceTable(*this);
}

void ConvergenceTable::dumpOneResult(double result) {
    innerMCStatistics->dumpOneResult(result);
    ++pathsDone;
    
    if (pathsDone == stoppingPoint) {
        stoppingPoint *= 2;
        std::vector<std::vector<double>> thisResult(innerMCStatistics->getResultsSoFar());
        
        for (unsigned long i = 0; i < thisResult.size(); i++) {
            thisResult[i].push_back(pathsDone);
            resultsSoFar.push_back(thisResult[i]);
        }
    }
}

std::vector<std::vector<double>> ConvergenceTable::getResultsSoFar() const {
    std::vector<std::vector<double>> temp(resultsSoFar);

    if (pathsDone * 2 != stoppingPoint) {
        std::vector<std::vector<double>> thisResult(innerMCStatistics->getResultsSoFar());
        
        for (unsigned long i = 0; i < thisResult.size(); i++) {
            thisResult[i].push_back(pathsDone);
            temp.push_back(thisResult[i]);
        }
    }
    return temp;
}
