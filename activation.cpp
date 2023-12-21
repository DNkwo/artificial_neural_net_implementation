//activation.cpp
//activation functions for the neurons

#include "include/activation.h"
#include <cmath>

//Activations

double Activation::fastSigmoid(double val)
{
    return val / (1 + std::abs(val));
}

//Derivatives

double Activation::fastSigmoidDerivative(double val)
{
    return val * (1 - val);
}