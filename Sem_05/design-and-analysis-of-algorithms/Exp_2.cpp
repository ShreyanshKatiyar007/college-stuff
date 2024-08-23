// implement power function in O(logn) time complexity.

#include <iostream>
using namespace std;

double power(double base, int exponent)
{

    if (exponent == 0)
    {
        return 1.0;
    }

    bool isNegative = false;
    if (exponent < 0)
    {
        isNegative = true;
        exponent = -exponent;
    }

    double result = 1.0;
    double current_product = base;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result *= current_product;
        }
        current_product *= current_product;
        exponent /= 2;
    }

    if (isNegative)
    {
        return 1.0 / result;
    }

    return result;
}

int main()
{
    double base;
    int exponent;

    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exponent;

    double result = power(base, exponent);
    cout << base << " raised to the power of " << exponent << " is " << result << endl;

    return 0;
}
