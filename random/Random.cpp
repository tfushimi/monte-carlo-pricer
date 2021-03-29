#include "Random.hpp"
#include "NormalDistribution.hpp"
#include <valarray>

void RandomBase::getGaussians(std::valarray<double> &variates) {
    getUniforms(variates);
    
    for (unsigned long i = 0; i < dimension; i++) {
        double x = variates[i];
        variates[i] = normalInvCDF(x);
    }
}

void RandomBase::resetDimension(unsigned long newDimension) {
    dimension = newDimension;
}

RandomBase::RandomBase(unsigned long dimension) : dimension(dimension) {
    
}
