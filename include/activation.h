class Activation
{
    public:
    
    //Fast Sigmoid Function (easy to get derivative)
    // f(x) = x / (1 + |x|)
    static double fastSigmoid(double val);

     //derivative 
        // f'(x) = f(x) * (1 - f(x))
    static double fastSigmoidDerivative(double val);



};