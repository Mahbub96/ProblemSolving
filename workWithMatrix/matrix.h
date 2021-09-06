#include <iostream>
#include <vector>
int SIZE;
using namespace std;

vector<vector<int>> matrixInput(unsigned row, unsigned col)
{
    vector<vector<int>> matrix(row);

    for (int i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            int temp;
            cin >> temp;
            matrix[i].push_back(temp);
        }
    }
    return matrix;
}

/**
 * identityMatrix - returns a vector of identity matrix
 * param int n - size of the matrix 
 **/
vector<vector<int>> identityMatrix(int n)
{
    vector<vector<int>> I(n);
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
        {
            if (i == j)
                I.at(i).push_back(1);

            else
                I.at(i).push_back(0);
        }
    return I;
}

vector<vector<int>> matrixAdd(vector<vector<int>> m1, vector<vector<int>> m2)
{
    int size = m1.size();
    vector<vector<int>> result(size);
    if (m1.size() != m2.size())
    {
        cout << "Inputted two matrix's are must be same row and collumn" << endl;
        return result;
    }
    for (size_t i = 0; i < m1.size(); i++)
    {
        for (size_t j = 0; j < m1[i].size(); j++)
        {
            result[i].push_back(m1[i][j] + m2[i][j]);
        }
    }
    return result;
}

vector<vector<int>> matrixMul(vector<vector<int>> m1, vector<vector<int>> m2)
{
    vector<vector<int>> result(m1.size());

    if (m1[0].size() != m2.size())
    {
        cout << "First matrix's column and Second matrix's Row must be equal!" << endl;
        return result;
    }

    for (size_t p = 0; p < m1.size(); p++)
    {
        for (size_t row = 0; row < m2[0].size(); row++)
        {
            int temp = 0;
            for (size_t col = 0; col < m1[0].size(); col++)
            {
                temp += m1[p][col] * m2[col][row];
            }
            result[p].push_back(temp);
        }
    }

    return result;
}

vector<vector<int>> transpose(vector<vector<int>> m)
{
    vector<vector<int>> result(m[0].size());
    for (size_t row = 0; row < m[0].size(); row++)
    {
        for (size_t col = 0; col < m.size(); col++)
        {
            result[row].push_back(m[col][row]);
        }
    }

    return result;
}

void show(vector<vector<int>> &v)
{

    for (size_t i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

// void showRec(vector<vector<int>> &v, int i, int j)
// {
//     if (i == v.size())
//         return;

//     if (j == v[0].size())
//     {
//         while (j)
//             cout << v[i].at(v[0].size() - j--) << " ";

//         cout << endl;
//         return;
//     }
//     showRec(v, i, j + 1);

//     showRec(v, i + 1, j);
// }

/* Polin's Mod */
void showRec(vector<vector<int>> &v, int i, int j)
{
    if (i == v.size() || j == v.size())
        return;

    cout << v[i][j] << " "; /* Print visited value */
    showRec(v, i, j + 1);

    cout << endl;

    if (i < v.size())
        showRec(v, i + 1, 0);
    else
        SIZE = false;
}

void showRecurrent(vector<vector<int>> &v)
{
    SIZE = v.size() - 1;
    showRec(v, 0, 0);
}