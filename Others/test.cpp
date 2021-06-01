#include <iostream>
#include <vector>
using namespace std;
int food = 0;
int step = 0;

void generateSubsets(vector<int> &subset, int i, vector<int> &nums)
{

    if (i == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << subset[i] << " \n";
            return;
            /* code */
        }
    }
    // Put empty set
    generateSubsets(subset, i + 1, nums);
    subset.push_back(nums[i]);
    generateSubsets(subset, i + 1, nums);
    subset.pop_back();
}

void wayFinder(vector<vector<char>> &v, int x, int y)
{
}

int shortestPath(vector<vector<char>> &v, int right, int down, int n)
{

    if (v[right][down] == 'f')
        food++;
    if ((right + 1 < n && v[right + 1][down] != 'r'))
    {
        step++;
        cout << "Step:" << step << " R:" << right << " D:" << down << " F:" << food << endl;
        shortestPath(v, right + 1, down, n);
    }

    else if (down + 1 < n && v[right][down + 1] != 'r')
    {
        step++;
        cout << "Step:" << step << " R:" << right << " D:" << down << " F:" << food << endl;

        shortestPath(v, right, down + 1, n);
    }
    if (right == down && down == n)
        return step;
    return step;
}

void print2d(vector<vector<char>> v)
{
    cout << endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> subsets, nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    generateSubsets(subsets, 3, nums);

    vector<vector<char>> v(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char temp;
            cin >> temp;
            v[i].push_back(temp);
        }
    }
    print2d(v);
    cout << shortestPath(v, 0, 0, 3) << endl;

    return 0;
}