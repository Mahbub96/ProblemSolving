#include <iostream>
#include <string>

using namespace std;

void leterC(int x, int y)
{
    if (y == 3 || (y < 3 && x == 0))
        cout << "*";
    else
        cout << " ";

    if (x == 6)
    {
        cout << "  ";
        return;
    }
    leterC(x + 1, y);
}
void leterA(int x, int y)
{
    // cout << y;
    // if ((y == 3 && (x > 1 && x < 5)) || (y == 2 && (x == 1 || x == 5)) || (y <= 1 && (x == 0 || x == 6)) || (y == 0 && x < 7))
    //     cout << "*";
    // else
    //     cout << " ";

    // if (x == 6)
    // {
    //     cout << "  ";
    //     return;
    // }

    // return leterA(x + 1, y);
}
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
void leterO(int x, int y)
{
    if (((x > 0 && x < 6) && y == 3) || ((x == 6 || !x) && y != 3))
        cout << "*";
    else
        cout << " ";
    if (x == 6)
    {
        cout << "  ";
        return;
    }
    return leterO(x + 1, y);
}
void leterX(int x, int y)
{
    if ((y == 3 && (x == 0 || x == 6) || (y == 2 && (x == 1 || x == 5)) || (y == 1 && (x == 2 || x == 4)) || (y == 0 && x == 3)))
        cout << "*";
    else
        cout << " ";
    if (x == 6)
    {
        cout << "  ";
        return;
    }
    return leterX(x + 1, y);
}

void word(int y, string &str)
{
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        if (str[i] == 'A')
            leterA(0, y);
        else if (str[i] == 'B')
            leterB(0, y);
        else if (str[i] == 'C')
            leterC(0, y);

        else if (str[i] == 'D')
            leterD(0, y);
        else if (str[i] == 'E')
            leterE(0, y);
        else if (str[i] == 'H')
            leterH(0, y);
        else if (str[i] == 'I')
            leterI(0, y);
        else if (str[i] == 'K')
            leterK(0, y);
        else if (str[i] == 'O')
            leterO(0, y);
        else if (str[i] == 'X')
            leterX(0, y);
        else if (str[i] == ' ')
            space();
    }
}

/**
 * @brief To print a word using star(*) sign
 * 
 * @param y Required 3  | this is size parameter of y axis
 * @param str required string type word and uppercase everyChar
 */
void patternWord(int y, string &str)
{

    word(y, str);
    cout << endl;
    if (!y)
        return;
    patternWord(y - 1, str);
    word(y, str);

    cout << endl;
}

int main()
{
    string str = "C C";
    patternWord(3, str);
    return 0;
}