#ifndef ParkMiller_hpp
#define ParkMiller_hpp
#include "Random.hpp"
#include <valarray>

class ParkMiller {
public:
    ParkMiller(long seed=1);
    
    long getOneRandomInt();
    void setSeed(long seed);
    
    static unsigned long max();
    static unsigned long min();

private:
    long seed;
};

class RandomParkMiller: public RandomBase {
public:
    RandomParkMiller(unsigned long dimension, unsigned long seed=1);
    
    virtual RandomBase* clone() const;
    virtual void getUniforms(std::valarray<double>& variates);
    virtual void skip(unsigned long numberOfPaths);
    virtual void setSeed(unsigned long seed);
    virtual void reset();
    virtual void resetDimension(unsigned long newDimension);
    
private:
    ParkMiller generator;
    unsigned long initSeed;
    double reciprocal;  // the reciprocal of the maximum value plus one
};
#endif