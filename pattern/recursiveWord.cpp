#include <iostream>
using namespace std;

void leterE(int x, int y)
{
    if (y == 3 || (y == 1 && (x == 0 || x == 3)) || ((y == 0 && (x <= 3))) || (y == 2 && (x == 0 || x == 6)))
        cout << "*";
    else
        cout << " ";

    if (x == 6)
    {
        cout << "  ";
        return;
    }

    return leterE(x + 1, y);
}
void leterI(int x, int y)
{
    if (y == 3 || (x == 1))
        cout << "*";

    else
        cout << " ";

    if (x == 2)
    {
        cout << "  ";
        return;
    }
    return leterI(x + 1, y);
}
void leterD(int x, int y)
{
    if (!x || (y == 3 && x < 3) || (y == 2 && x == 4) || (y < 2 && x == 5))
        cout << "*";

    else
        cout << " ";
    if (x == 6)
    {
        cout << " ";
        return;
    }
    return leterD(x + 1, y);
}
void space()
{
    cout << "   ";
}
void leterB(int x, int y)
{
    if (!x || (y == 3 && x < 6) || (y == 0 && x < 6) || (y == 2 && x == 6) || (y == 1 && x == 6))
        cout << "*";

    else
        cout << " ";
    if (x == 6)
    {
        cout << "  ";
        return;
    }
    return leterB(x + 1, y);
}
void leterH(int x, int y)
{
    if (!x || ((y < 3 || y) && (!x || x == 6)) || !y)
        cout << "*";

    else
        cout << " ";
    if (x == 6)
    {
        cout << "  ";
        return;
    }
    return leterH(x + 1, y);
}
void leterK(int x, int y)
{
    if (!x || (x == 6 && y == 3) || (x == 4 && y == 2) || (x == 2 && y == 1) || (y == 0 && x == 1))
        cout << "*";
    else
        cout << " ";
    if (x == 6)
    {
        cout << "  ";
        return;
    }
    return leterK(x + 1, y);
}
void word(int y)
{
    leterE(0, y);
    leterI(0, y);
    leterD(0, y);
    space();
    // leterB(0, y);
    // leterH(0, y);
    leterK(0, y);
}
void callLeter(int y)
{

    word(y);
    cout << endl;
    if (!y)
        return;
    callLeter(y - 1);
    word(y);

    cout << endl;
}

int main()
{
    callLeter(3);
    return 0;
}