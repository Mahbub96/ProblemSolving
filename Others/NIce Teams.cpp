/* Incomplete Problem */
#include <iostream>
#include <vector>

using namespace std;
class Result
{
public:
    int res, x, y;
} r;
int pairs(vector<long int> v, int minDiff)
{
}

int main()
{
    int n;
    cin >> n;
    vector<long int> v;
    for (int i = 0; i < n; i++)
    {
        /* code */
        long int temp;
        cin >> temp;
        v.push_back(temp);
    }
    int minDiff;
    cin >> minDiff;
    cout << pairs(v, minDiff);

    return 0;
}