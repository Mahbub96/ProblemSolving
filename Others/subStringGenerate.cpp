#include <iostream>
#include <vector>

using namespace std;

void generate(vector<int> &v, int i, vector<int> &arr)
{

    if (v.size() == i)
    {
    }
    /*** when empty set generate ***/
    generate(v, i + 1, arr);
    v.push_back(arr[i]);
}

int main()
{
    vector<char> arr;
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        char temp;
        cin >> temp;
        arr.push_back(temp);
    }

    vector<int> empty;

    generate(empty, 0, arr);

    return 0;
}