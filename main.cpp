#include <iostream>
#include "include/neuron.h"
#include "include/matrix.h"
#include "include/neuralnetwork.h"
#include "include/utils/utils.h"


int main(int argc, char **argv)
{
    // Neuron *n = new Neuron(0.9);
    // cout << "Val: " << n->getVal() << endl;
    // cout << "Activated Val: " << n->getActivatedVal() << endl;
    // cout << "Derived Val: " << n->getDerivedVal() << endl;
    
    Matrix *m = new Matrix(3, 2, true);
    m->printToConsole();

    Matrix *tm = m->transpose();
    tm->printToConsole();

    Matrix *fm = utils::Utils::multiplyMatrices(m, tm);

    fm->printToConsole();

    //attempting to generate a simple nn
    // vector<size_t> net_topology;
    // net_topology.push_back(3);
    // net_topology.push_back(2);
    // net_topology.push_back(3);

    // vector<double> input_layer;
    // input_layer.push_back(1.0);
    // input_layer.push_back(0.0);
    // input_layer.push_back(1.0);


    // NeuralNetwork *nn = new NeuralNetwork(net_topology);
    // nn->setInputVector(input_layer);

    // nn->printToConsole();

    // delete nn;



    return 0;
}