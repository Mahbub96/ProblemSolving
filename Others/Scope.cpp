#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference
{
private:
    vector<int> elements;

public:
    int maximumDifference;

    Difference(vector<int> a)
    {
        maximumDifference = 0;
        elements = a;
    }

    void computeDifference()
    {
        int temp = 0;
        for (int i = 0; i < elements.size(); i++)
        {
            /* code */
            int tempValue = elements[i];

            for (int j = i + 1; j < elements.size(); j++)
            {
                /* code */
                temp = abs(tempValue - elements[j]);
                maximumDifference = max(temp, maximumDifference);
            }
        }
    }
    // Add your code here

}; // End of Difference class

int main()
{
    int N;
    cin >> N;

    vector<int> a;

    for (int i = 0; i < N; i++)
    {
        int e;
        cin >> e;

        a.push_back(e);
    }

    Difference d(a);

    d.computeDifference();

    cout << d.maximumDifference;

    return 0;
}