#include <iostream>
#include <vector>

using namespace std;

int migratoryBirds(vector<int> arr)
{
    int myArr[6] = {}; // Set all index's value are 0

    int index = 1;
    int maxValue = 0;

    for (size_t i = 0; i < arr.size(); i++)
        myArr[arr[i]]++;

    for (size_t i = 1; i < 6; i++)
    {
        if (myArr[i] > maxValue)
        {
            maxValue = myArr[i];
            index = i;
        }
    }

    return index;
}

int main()
{

    int n;
    cin >> n;
    vector<int> v;
    for (size_t i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    int result = migratoryBirds(v);

    cout << result << "\n";

    return 0;
}
