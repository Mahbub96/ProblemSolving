#include <iostream>
#include <vector>

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
    vector<vector<int>> result(m1[0].size());
    if (m1[0].size() != m2.size())
    {
        cout << "First matric's Row and second matrix's Column must be equal" << endl;
        return result;
    }

    for(int resultRow = 0; resultRow<result.size();resultRow++){
        for(int row = 0; row < m1[resultRow].size(); row++){
        int temp = 0;
            for(int col = 0; col < m2.size(); col++){
                temp += m1[row][col]*m2[col][row];
            }
            result[resultRow].push_back(temp);
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

void showRec(vector<vector<int>> &v, int i, int j)
{
    if (j == v.size())
    {
        while (j)
        {
            cout << v[i][j] << " ";
            --j;
        }
        return;
    }

    showRec(v, i, j + 1);

    showRec(v, i + 1, j);
    cout << endl;
    return;
}
