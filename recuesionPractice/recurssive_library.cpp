#include <iostream>
#include <cmath>

using namespace std;
int step = 0;

int piece(int n)
{
    if (!n)
        return 1;

    return n + piece(n - 1);
}

double fibonakki(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    return fibonakki(n - 1) + fibonakki(n - 2);
}

double moveCounter(int x)
{
    if (x == 1)
        return 1;
    return (2 * moveCounter(x - 1) + 1);
}

void towerofHenoi(int n, char source, char des, char aux)
{
    if (n == 1)
    {
        cout << "Move from " << source << " to " << des << endl;
        return;
    }

    towerofHenoi(n - 1, source, aux, des);
    cout << "Move from " << source << " to " << des << endl;
    towerofHenoi(n - 1, aux, des, source);
}
int zigSolve(int n)
{
    if (n == 0)
        return 1;
    return zigSolve(n - 1) + (4 * n) - 3;
}

// Not recursively its closeform for this problem
// int zigSolve(int n)
// {
//     return (2 * n * n) - n + 1;
// }
int JosephusProblem(int n)
{
    int power = log(n) / log(2);
    int l = n - pow(2, power);
    // while (n & (n - 1)) // for finding last n = 2^x form
    // {
    //     l++;
    //     n--;
    // }
    return (2 * l) + 1;
}
bool isEven(int n)
{
    return (n & 1);
}
int main()
{

    // towerofHenoi(3, 'A', 'C', 'B');
    // cout << piece(3) << endl;
    // cout << moveCounter(6) << endl;
    // cout << fibonakki(5) << endl;
    // cout << linesInPlaneProblem(10) << endl;
    // cout << zigSolve(3) << endl;
    // cout << JosephusProblem(10) << endl;
    // cout << isEven(10) << endl;

    return 0;
}
