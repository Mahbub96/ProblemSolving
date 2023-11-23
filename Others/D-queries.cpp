#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     int temp;
    //     cin >> temp;
    //     arr[i] = temp;
    // }
    // int q;
    // cin >> q;
    // int pair[q * 2];
    // for (int i = 0; i < q; i += 2)
    // {
    //     int a, b;
    //     cin >> a >> b;
    //     pair[i] = a;
    //     pair[i + 1] = b;
    // }

    // map<int, int> m;
    // for (int i = 0; i < q; i += 2)
    // {
    //     map.insert()
    // }
    int arr[] = {1, 2, 3, 2, 1};
    map<int, int> m(arr, arr + 4);

    for (auto i = m.begin(); i < m.end(); i++)
    {
        /* code */
        cout << i->first() << " : " << i->second() << endl;
    }

    return 0;
}