/* Incomplete project */
#include <iostream>
#include <vector>

using namespace std;

void lstDia(vector<vector<int>> &v)
{
    int count = 0;
    for (size_t i = 0; i < 3; i++)
    {
        count += v[i][2 - i];
    }

    if (count > 15)
        v[2][2] -= count - 15;
    else if (count < 15)
        v[2][2] += 15 - count;
}
void fstDia(vector<vector<int>> &v)
{
    int count = 0;
    for (size_t i = 0; i < 3; i++)
    {
        count += v[i][i];
    }
    if (count > 15)
        v[2][2] -= count - 15;
    else if (count < 15)
        v[2][2] += 15 - count;
}

void checkCol(vector<vector<int>> &v, int i)
{
    int count;
    for (size_t j = 0; j < 3; j++)
    {
        count += v[j][i];
    }
    if (count > 15)
        v[2][i] -= count - 15;
    else if (count < 15)
        v[2][i] += 15 - count;
}

void checkRow(vector<vector<int>> &v, int i)
{
    int count = 0;
    for (size_t j = 0; j < v.size(); j++)
    {
        count += v[i][j];
    }
    if (count > 15) /* if large */
        v[i][2] -= count - 15;
    else if (count < 15)
        v[i][2] += 15 - count;
}

void formingMagicSquare(vector<vector<int>> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        checkRow(v, i);
        checkCol(v, i);
        if (i == 0)
            fstDia(v);
        if (i == 2)
            lstDia(v);
    }
}
int main()
{
    vector<vector<int>> v(3);
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
        {
            int temp;
            cin >> temp;
            v[i].push_back(temp);
        }
    formingMagicSquare(v);

    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}