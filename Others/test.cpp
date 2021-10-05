#include <iostream>
using namespace std;

class num
{
    long int a, b, c;

public:
    num(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void getValue()
    {
        cout << a * b * c << endl;
    }
};

int main()
{
    num n(1039, 3749, 8473);
    n.getValue();
    return 0;
}