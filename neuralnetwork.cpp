#include "include/neuralnetwork.h"
#include <string>


NeuralNetwork::NeuralNetwork(std::vector<size_t> topology)
{
    this->topology = topology;
    this->topologySize = topology.size();

    for(size_t i = 0; i < topologySize; i++)
    {
        Layer *l = new Layer(topology[i]);
        this->layers.push_back(l);
    }

    for(size_t i = 0; i < (topologySize - 1); i++)
    {
        Matrix *m = new Matrix(topology[i], topology[i+1], true);
        this->weightMatrices.push_back(m);
    }
}

void NeuralNetwork::setInputVector(std::vector<double> inputVector)
{
    this->inputVector = inputVector;

    for(size_t i = 0; i < inputVector.size(); i++)
    {
        this->layers[0]->setVal(i, inputVector[i]);
    }
}

void NeuralNetwork::printToConsole()
{
    for(size_t i = 0; i < this->layers.size(); i++)
    {   
        Layer* layer = layers[i];
        Matrix *m;
        if(i == 0) //if it is the input layer
        {
            m = layer->convertValToMatrix();
        }
        else // any other layers
        {
            m = layer->convertActivatedValsToMatrix();
        }
        m->printToConsole();
    }
}