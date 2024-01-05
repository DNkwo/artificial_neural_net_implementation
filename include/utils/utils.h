#ifndef _UTILS_H_
#define _UTILS_H_

#include "../matrix.h"

namespace utils
{
    class Utils
    {
        public:
        
        //Fast Sigmoid Function (easy to get derivative)
        // f(x) = x / (1 + |x|)
        static double fastSigmoid(double val);

        //derivative 
            // f'(x) = f(x) * (1 - f(x))
        static double fastSigmoidDerivative(double val);

        //multiply matrices
        static Matrix* multiplyMatrices(Matrix *a, Matrix *b);

        //convert nxm matrix to 1-(nxm) vector
        static Matrix* matrixToVector(Matrix *a);

    };
}
#endif