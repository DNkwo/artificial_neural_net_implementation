//neuron.cpp

#include "include/neuron.h"
#include "include/activation.h"

//Constructor

Neuron::Neuron(double val)
{
    this->val = val;

    //we've used fixed activation functions at the moment
    activate(Activation::fastSigmoid); //activates value
    derive(Activation::fastSigmoidDerivative); //then finds derivate value
}

//Fast Sigmoid Function (easy to get derivative)
// f(x) = x / (1 + |x|)
void Neuron::activate(double (*activationFunction)(double))
{
    this->activatedVal = activationFunction(this->val);
}

//derivative 
// f'(x) = f(x) * (1 - f(x))
void Neuron::derive(double (*derivativeFunction)(double))
{
    this->derivedVal = derivativeFunction(this->activatedVal);
}