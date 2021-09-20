#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n, q;
    cin >> n >> q;

    vector<vector<int>> arr(n);
    for (size_t i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        for (size_t j = 0; j < s; j++)
        {
            int val;
            cin >> val;
            arr[i].push_back(val);
        }
    }

    for (size_t i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << arr[x][y] << endl;
    }

    return 0;
}