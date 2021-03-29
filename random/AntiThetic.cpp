#include "AntiThetic.hpp"
#include "Random.hpp"
#include "Wrapper.hpp"

AntiThetic::AntiThetic(const Wrapper<RandomBase>& generator) : RandomBase(*generator), generator(generator) {
    this->generator->reset();
    oddEven = true;
    nextVariates.resize(getDimension());
}

RandomBase* AntiThetic::clone() const {
    return new AntiThetic(*this);
}

void AntiThetic::getUniforms(std::valarray<double>& variates) {
    if (oddEven) {
        generator->getUniforms(variates);
        
        for (unsigned long i = 0; i < getDimension(); i++) {
            nextVariates[i] = 1.0 - variates[i];
        }
        
        oddEven = false;
    } else {
        variates = nextVariates;
        oddEven = true;
    }
}

void AntiThetic::skip(unsigned long numberOfPaths) {
    if (numberOfPaths == 0) return;
    if (oddEven) {
        oddEven = false;
        numberOfPaths--;
    }
    
    generator->skip(numberOfPaths / 2);
    
    if (numberOfPaths % 2 != 0) {
        std::valarray<double> temp(getDimension());
        
        getUniforms(temp);
    }
}

void AntiThetic::setSeed(unsigned long seed) {
    generator->setSeed(seed);
    oddEven = true;
}

void AntiThetic::resetDimension(unsigned long newDimension) {
    RandomBase::resetDimension(newDimension);
    
    nextVariates.resize(newDimension);
    
    generator->resetDimension(newDimension);
}

void AntiThetic::reset() {
    generator->reset();
    oddEven = true;
}
