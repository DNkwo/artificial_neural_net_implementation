#ifndef _MATRIX_H
#define _MATRIX_H

#include <iostream>
#include <vector>

class Matrix
{
    private:
        size_t numRows;
        size_t numCols;
        std::vector< std::vector<double> > elementValues;
    public:
        Matrix(size_t numRows, size_t numCols, bool isRandom);

        Matrix *transpose(); //returns pointer to matrix
        double generateRndValue();

        //setters
        void setValue(size_t rowVal, size_t colVal, double val);
        void setNumRows(size_t numRows) { this->numRows = numRows; }
        void setNumCols(size_t numCols) { this->numCols = numCols; }

        //getters
        double getValue(size_t row, size_t col) { return this->elementValues[row][col]; }
        size_t getNumRows() { return this->numRows; }
        size_t getNumCols() { return this->numCols; }

        void printToConsole();
};

#endif