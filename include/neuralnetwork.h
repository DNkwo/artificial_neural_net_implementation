#ifndef _NEURAL_NETWORK_H_
#define _NEURAL_NETWORK_H_


#include "matrix.h"
#include "layer.h"

class NeuralNetwork
{
    private:
        //represents num of neurons per layer
        std::vector<size_t>     topology;
        std::vector<Layer *>    layers;
        std::vector<Matrix *>   weightMatrices; 
        std::vector<double>     inputVector;

        size_t topologySize;
    public:
        NeuralNetwork(std::vector<size_t> topology);
        void setInputVector(std::vector<double> input);
        void printToConsole();
};

#endif