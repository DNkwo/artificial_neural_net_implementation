#include "include/layer.h"

Layer::Layer(size_t size)
{   
    //generates the neurons for the layer
    for(size_t i = 0; i < size; i++)
    {
        Neuron *n = new Neuron(0.00);
        this->neurons.push_back(n);
        
    }
}

void Layer::setVal(size_t index, double val)
{
    this->neurons[index]->setVal(val);
}

Matrix *Layer::convertValToMatrix()
{
    Matrix *m = new Matrix(1, this->neurons.size(), false);
    for(size_t i = 0; i < this->neurons.size(); i++)
    {
        m->setValue(0, i, this->neurons[i]->getVal());
    }

    return m;
}

Matrix *Layer::convertActivatedValsToMatrix()
{
    Matrix *m = new Matrix(1, this->neurons.size(), false);
    
    for(size_t i = 0; i < this->neurons.size(); i++)
    {
        m->setValue(0, i, this->neurons[i]->getActivatedVal());
    }

    return m;
}

Matrix *Layer::convertDerivedValsToMatrix()
{
    Matrix *m = new Matrix(1, this->neurons.size(), false);
    
    for(size_t i = 0; i < this->neurons.size(); i++)
    {
        m->setValue(0, i, this->neurons[i]->getDerivedVal());
    }

    return m;
}

