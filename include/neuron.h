#ifndef _NEURON_H_
#define _NEURON_H_


#include <iostream>

class Neuron
{
    private:
        double val; //raw value
        double activatedVal; //will fit a value to bounds of activation function
        double derivedVal; //approximate derivative of activated value (used for bckppg)
    public:

        //constructor
        Neuron(double val);

        //set value
        void setVal(double val);

        void activate(double (*activationFunction)(double));

        void derive(double (*derivativeFunction)(double));

        //getters
        double getVal() { return this-> val; }
        double getActivatedVal() { return this->activatedVal; }
        double getDerivedVal() { return this->derivedVal; }

};


#endif