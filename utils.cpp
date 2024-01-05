//Utils.cpp
//Utils functions for the neurons

#include "include/utils/utils.h"
#include <cmath>
#include <cassert>

//Utilss

double utils::Utils::fastSigmoid(double val)
{
    return val / (1 + std::abs(val));
}

//Derivatives

double utils::Utils::fastSigmoidDerivative(double val)
{
    return val * (1 - val);
}

Matrix* utils::Utils::multiplyMatrices(Matrix *a, Matrix *b)
{
    //in-efficient method of matrix multiplication

    if(a->getNumCols() != b->getNumRows()) // if A(m) != B(n)
    {
        std::cerr << "A_rows: " << a->getNumCols() << " != B_cols: " << b->getNumCols() << std::endl;
        assert(false);
    }

    Matrix *c = new Matrix(a->getNumRows(), b->getNumCols(), false);

    //multiplication step (using for loops :<)
    //loop dependency 
    for(size_t i = 0; i < a->getNumRows(); i++) 
    {
        for(size_t k = 0; k < b->getNumCols(); k++)
        {
            double temp = 0;
            for(size_t m = 0; m < c->getNumRows(); m++)
            {
                //C(i,k) = sum<m>[A(i+m) * B(k+m)]
                double element_a = a->getValue(i, m);
                double element_b = b->getValue(m, k);

                temp += element_a * element_b;

            }
            c->setValue(i, k, temp);
        }
    }

    return c;

}


Matrix* utils::Utils::matrixToVector(Matrix *a)
{
    //loop through colums and rows and add to vector
    Matrix* out
}