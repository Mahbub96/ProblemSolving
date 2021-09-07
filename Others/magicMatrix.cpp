/* Incomplete project */
#include <iostream>
#include <vector>

using namespace std;

class Position
{
public:
    int x;
    int y;
    int value;
    Position(int value, int x, int y)
    {
        this->value = value;
        this->x = x;
        this->y = y;
    }
    Position()
    {
        this->value = -1;
        this->x = -1;
        this->y = -1;
    }
};
/* This function will find Duplicated numbers list if exists */
vector<Position> replaceableValue;

void put_value_and_check(int n, vector<vector<int>> &v)
{
}

void finalChecking(vector<vector<int>> &v, vector<Position> provableNumberDetails)
{
    for (size_t n = 0; n < provableNumberDetails.size(); n++)
    {
        int temp = provableNumberDetails[n];
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                put_value_and_check(temp, v);
            }
        }
    }
}

void findDuplicate(vector<vector<int>> &v, int value)
{
    short unsigned int times = 0;
    Position position;
    Position first;
    /* find how many times exists this value on this vector */
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (value == v[i][j])
            {
                ++times;
                if (times == 1)
                {
                    first.x = i;
                    first.y = j;
                    first.value = value;
                }

                if (times > 1)
                {
                    if (times == 2)
                        replaceableValue.push_back(first);
                    position.x = i;
                    position.y = j;
                    position.value = value;
                    replaceableValue.push_back(position);
                }
            }
        }
    }
}

vector<Position> findProvableNumberSet(vector<vector<int>> &v)
{
    vector<Position> provableNumberDetails;
    // find duplicate
    for (size_t x = 1; x <= 9; x++)
        findDuplicate(v, x);

    /* find missing number */
    for (size_t x = 1; x <= 9; x++)
    {
        bool isMissing = true;
        Position missingNumber;
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
        {
            missingNumber.value = x;
            provableNumberDetails.push_back(missingNumber);
        }
    }

    return provableNumberDetails;
}

void formingMagicSquare(vector<vector<int>> s)
{
    // "provableNumberDetails" and "replaceableValue"are two array which type is Position
    /* find missing numbers and duplicated number,they are provlble output */
    vector<Position> provableNumberDetails = findProvableNumberSet(s);

    finalChecking(s, provableNumberDetails)

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