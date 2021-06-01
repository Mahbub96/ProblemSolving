#include <iostream>

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

// debugging mode
void towerofHenoi(int n, char source, char des, char aux)
{
    if (n == 0)
        return;
    cout << "B, step : " << step << " n:" << n << " -> Move from " << source << " to " << des << endl;

    towerofHenoi(n - 1, source, aux, des);
    cout << " , step : " << ++step << " n:" << n << " -> Move from " << source << " to " << des << endl;
    towerofHenoi(n - 1, aux, des, source);
    cout << "L, step : " << step << " n:" << n << " -> Move from " << source << " to " << des << endl;
}
int zigSolve(int n)
{
    if (n == 0)
        return 1;
    return zigSolve(n - 1) + (4 * n) - 3;
}
int main()
{

    // cout << piece(10);
    // cout << moveCounter(6);
    // towerofHenoi(2, 'A', 'C', 'B');
    // cout << fibonakki(5);
    // for (int i = 1; i <= 10; i++)
    // {
    //     cout << fibonakki(i) << ' ';
    // }
    // cout << linesInPlaneProblem(3);
    cout << zigSolve(6);
    return 0;
}