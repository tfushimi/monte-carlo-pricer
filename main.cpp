#include "SimpleMC.hpp"
#include "ParkMiller.hpp"
#include<iostream>
#include "VanillaOption.hpp"
#include "MCStatistics.hpp"
#include "ConvergenceTable.hpp"
#include "AntiThetic.hpp"
#include "Parameter.hpp"
#include "ExoticBSEngine.hpp"
#include "AsianOption.hpp"
#include <valarray>

using std::cout;
using std::endl;
using std::vector;

int main() {
    double expiry = 1;
    double strike = 100;
    double spot = 100;
    double vol = 0.2;
    double rate = 0.01;
    double dividend = 0.001;
    unsigned long numberOfPaths = 20000;
    unsigned long numberOfAveragingDates = 5;

    // Parameters (ideally, we should get these from market data)
    ParameterConstant volParam(vol);
    ParameterConstant rateParam(rate);
    ParameterConstant dividendParam(dividend);
    
    // RNG
    MCStatisticsMean mcStatisticsMean;
    ConvergenceTable convergenceTable(mcStatisticsMean);
    RandomParkMiller generator(1);
    AntiThetic antitheticGenerator(generator);
    
    // call payoff
    PayOffCall callPayoff(strike);
    
    // Vanilla call option
    VanillaOption vanillaOption(callPayoff, expiry);
    
    // Asian call optioin
    std::valarray<double> averagingTimes(numberOfAveragingDates);
    for (unsigned long i = 0; i < numberOfAveragingDates; i++) {
        averagingTimes[i] = (i + 1.0) * expiry / numberOfAveragingDates;
    }
    AsianOption asianOption(averagingTimes, expiry, callPayoff);
    
    // Price vanilla call option
//    simpleMC(vanillaOption,
//             spot,
//             volParam,
//             rateParam,
//             numberOfPaths,
//             convergenceTable,
//             antitheticGenerator);
//
//    vector<vector<double>> vanillaOptioinResult = convergenceTable.getResultsSoFar();
//
//    cout <<"The vanilla call price the results are \n";
//    for (unsigned long i=0; i < vanillaOptioinResult.size(); i++) {
//        for (unsigned long j=0; j < vanillaOptioinResult[i].size(); j++) {
//            cout << vanillaOptioinResult[i][j] << " ";
//        }
//        cout << "\n";
//    }
//
//    generator.reset();
    
    // Price asian call option
    ExoticBSEngine exoticEngine(asianOption,
                                rateParam,
                                dividendParam,
                                volParam,
                                generator,
                                spot);
    
    exoticEngine.doSimulation(convergenceTable, numberOfPaths);
    
    vector<vector<double>> asianOptionResult = convergenceTable.getResultsSoFar();
    cout <<"The asian call price the results are \n";
    for (unsigned long i=0; i < asianOptionResult.size(); i++) {
        for (unsigned long j=0; j < asianOptionResult[i].size(); j++) {
            cout << asianOptionResult[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
