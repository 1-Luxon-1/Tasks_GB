#include <iostream>

class Power
{
public:
    Power(double n1 = 1, double n2 = 1)
    {
        num1 = n1; 
        num2 = n2;
    }

    Power(Power& P)
    {
        num1 = P.num1;
        num2 = P.num2;
    }

    void set(double n1, double n2)
    {
        num1 = n1;
        num2 = n2;
    }

    void calculate()
    {
        std::cout << num1 << '^' << num2 << '=' << pow(num1, num2) << std::endl;
    }

    void print()
    {
        std::cout << "num1 = " << num1 << std::endl;
        std::cout << "num2 = " << num2 << std::endl;
    }

private:
    double num1;
    double num2;
};