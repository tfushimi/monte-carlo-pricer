#ifndef AntiThetic_hpp
#define AntiThetic_hpp

#include "Random.hpp"
#include "Wrapper.hpp"

class AntiThetic : public RandomBase {
public:
    AntiThetic(const Wrapper<RandomBase>& generator);
    
    virtual RandomBase* clone() const;
    virtual void getUniforms(std::valarray<double>& variates);
    virtual void skip(unsigned long numberOfPaths);
    virtual void setSeed(unsigned long seed);
    virtual void resetDimension(unsigned long newDimension);
    virtual void reset();
    
private:
    Wrapper<RandomBase> generator;
    bool oddEven;
    std::valarray<double> nextVariates;
};
#endif