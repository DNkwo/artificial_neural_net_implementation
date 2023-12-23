#ifndef _LAYER_H_
#define _LAYER_H_

#include <iostream>
#include <vector>
#include "Neuron.h"
#include <cmath>
#include "Matrix.h"

class Layer
{
    private:
        size_t size;
        std::vector<Neuron *> neurons;
    public:
        Layer(size_t size);

        //getters
        size_t getSize(){ return size; }
        Neuron *getNeuron(size_t index) { return this->neurons[index]; }

        //setters
        void setVal(size_t index, double val);

        Matrix *convertValToMatrix();
        Matrix *convertActivatedValsToMatrix();
        Matrix *convertDerivedValsToMatrix();


};
#endif