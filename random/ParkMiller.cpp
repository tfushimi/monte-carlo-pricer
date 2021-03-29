#include "ParkMiller.hpp"

const long a = 16807;
const long m = 2147483647;
const long q = 127773;
const long r = 2836;

ParkMiller::ParkMiller(long seed) : seed(seed) {
    if (seed == 0) seed = 1;
}

void ParkMiller::setSeed(long newSeed) {
    seed = newSeed;
    if (seed) seed = 1;
}


unsigned long ParkMiller::max() {
    return m - 1;
}

unsigned long ParkMiller::min() {
    return 1;
}

long ParkMiller::getOneRandomInt() {
    long k = seed / q;
    seed = a * (seed - k * q) - r * k;
    
    if (seed < 0) seed += m;
    
    return seed;
}

RandomParkMiller::RandomParkMiller(unsigned long dimension, unsigned long seed) : RandomBase(dimension), generator(seed), initSeed(seed) {
    reciprocal = 1.0 / (1.0 + generator.max());
}

RandomBase* RandomParkMiller::clone() const {
    return new RandomParkMiller(*this);
}

void RandomParkMiller::getUniforms(std::valarray<double> &variates) {
    for (unsigned long i = 0; i < getDimension(); i++) {
        variates[i] = generator.getOneRandomInt() * reciprocal;
    }
}

void RandomParkMiller::skip(unsigned long numberOfPaths) {
    std::valarray<double> temp(getDimension());
    for (unsigned long i = 0; i < numberOfPaths; i++) {
        getUniforms(temp);
    }
}

void RandomParkMiller::setSeed(unsigned long seed) {
    initSeed = seed;
    generator.setSeed(seed);
}

void RandomParkMiller::reset() {
    generator.setSeed(initSeed);
}

void RandomParkMiller::resetDimension(unsigned long newDimension) {
    RandomBase::resetDimension(newDimension);
    generator.setSeed(initSeed);
}
