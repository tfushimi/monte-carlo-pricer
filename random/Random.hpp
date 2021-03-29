#ifndef Random_hpp
#define Random_hpp

#include <valarray>

class RandomBase {
public:
    RandomBase(unsigned long dimention);
    
    inline unsigned long getDimension() const;
    
    virtual RandomBase* clone() const=0;
    virtual void getUniforms(std::valarray<double>& variates)=0;
    virtual void skip(unsigned long numberOfPaths)=0;
    virtual void setSeed(unsigned long seed)=0;
    virtual void reset()=0;
    
    virtual void getGaussians(std::valarray<double>& variates);
    virtual void resetDimension(unsigned long newDimension);
    
    virtual ~RandomBase(){};
private:
    unsigned long dimension;
};

unsigned long RandomBase::getDimension() const {
    return dimension;
}

#endif
