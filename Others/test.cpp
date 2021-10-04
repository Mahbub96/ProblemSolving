#include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    Complex(int m, int d)
    {
        a = m;
        b = d;
    }
    friend ostream &operator<<(ostream &os, const Complex &complex);
};

ostream &operator<<(ostream &os, const Complex &complex)
{
    os << complex.a << '+' << complex.b << 'i';
    return os;
}

int main()
{
    Complex complex(5, 6);
    cout << complex;
}