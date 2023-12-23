#include "include/matrix.h"
#include <random>

double Matrix::generateRndValue()
{
    //Create rnd generator and seed it with std::random_device
    std::mt19937 gen(std::random_device{}());

    //Create a dist in rang [0, 1)
    std::uniform_real_distribution<> dist(0, 1);

    //generate a rnd num
    return dist(gen);
}

void Matrix::setValue(size_t rowVal, size_t colVal, double val)
{   
    //error-checking :)
    if (rowVal >= elementValues.size() || colVal >= elementValues[0].size())
    {
        throw std::out_of_range("Index out of matrix bounds");
    }
    elementValues[rowVal][colVal] = val;
}

Matrix::Matrix(size_t numRows, size_t numCols, bool isRandom)
{
    this->setNumRows(numRows);
    this->setNumCols(numCols);

    this->elementValues.resize(numRows, std::vector<double>(numCols, 0.0));

    //loop through rows and assign values
    for(size_t i = 0; i < numRows; i++)
    {
        std::vector<double> colValues;
        for(size_t j = 0; j < numCols; j++)
        {
            double r = 0.00;
            if(isRandom)
            {
                r = this->generateRndValue();
            }

            this->setValue(i, j, r);
        }
    }
}

Matrix *Matrix::transpose()
{
    //easier to just create a new matrix

    //switch cols and nums
    Matrix* tMatrix = new Matrix(this->numCols, this->numRows, false);

    //fill in transposed matrix values
    for(size_t i = 0; i < tMatrix->getNumRows(); i++)
    {
        for(size_t j = 0; j < tMatrix->getNumCols(); j++)
        {
            tMatrix->setValue(i,j, this->getValue(j,i));
        }
    }

    return tMatrix;
}

void Matrix::printToConsole()
{
    //loop through rows and assign values and print
    for(size_t i = 0; i < numRows; i++)
    {
        std::vector<double> colValues;
        for(size_t j = 0; j < numCols; j++)
        {
            std::cout << this->elementValues.at(i).at(j) << "\t\t";
        }
        std::cout << std::endl;
    }
}


