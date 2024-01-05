//neuron.cpp

#include "include/neuron.h"
#include "include/utils/utils.h"

//Constructor

Neuron::Neuron(double val)
{
    setVal(val);
}

void Neuron::setVal(double val)
{
    this->val = val;
    //we've used fixed activation functions at the moment
    activate(utils::Utils::fastSigmoid); //activates value
    derive(utils::Utils::fastSigmoidDerivative); //then finds derivate value
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
