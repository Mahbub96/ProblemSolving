#include <iostream>
#include <vector>

using namespace std;

class Rpos
{
public:
    int x;
    int y;
    Rpos(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    Rpos()
    {
        this->x = -1;
        this->y = -1;
    }
};

vector<Rpos> replaceableValue;

Rpos findDuplicate(vector<vector<int>> &v, int value)
{
    short int times = 0;
    Rpos r;

    for (size_t i = 0; i < 3; i++)
    {

        for (size_t j = 0; j < 3; j++)
        {
            /* code */
            if (v[i][j] == value)
            {
                times += 1;
                r.x = i;
                r.y = j;
                if (times > 1)
                {
                    r.x = i;
                    r.y = j;
                }
            }
        }
    }
    return r;
}

vector<int> findProvableNumberSet(vector<vector<int>> &v)
{
    vector<int> provableNumberList;
    // find duplicate
    for (size_t x = 1; x <= 9; x++)
    {
        Rpos val = findDuplicate(v, x);
        if (val.x != -1)
            replaceableValue.push_back(val);
    }

    /* find missing number */
    for (size_t x = 1; x <= 9; x++)
    {
        bool isMissing = true;

        for (size_t i = 0; i < 3; i++)
        {

            for (size_t j = 0; j < 3; j++)
            {
                if (x == v[i][j])
                {
                    isMissing = false;
                    break;
                }
            }
            if (!isMissing)
                break;
        }
        if (isMissing)
            provableNumberList.push_back(x);
    }

    return provableNumberList;
}

void formingMagicSquare(vector<vector<int>> s)
{
    /* find missing numbers and duplicated number,they are provlble output */
    vector<int> provableNumberList = findProvableNumberSet(s);
    for (size_t i = 0; i < provableNumberList.size(); i++)
    {
        cout << provableNumberList[i] << " ";
    }
    cout << endl;
    for (size_t i = 0; i < replaceableValue.size(); i++)
    {
        cout << replaceableValue[i].x << "," << replaceableValue[i].y << endl;
    }

    /* check horizontally vertivally and diagonally */
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
    return 0;
}