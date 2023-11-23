#include <algorithm>
#include <iostream>

using namespace std;

int findTimes(int *arr, int a, int b, int l)
{
  int s = b;
  int e = l - 1;
  int times;

  int lb = b;
  int ub = (arr[a] + arr[b]) - 1;

  if (ub > arr[b])
  {
    while (s <= e)
    {
      unsigned int m = s + (e - s) / 2;

      if (arr[s] > arr[m])
      {
        m -= 1;
        break;
      }

      if (arr[m] == ub)
      {
        ub = m;
        break;
      }
      if (arr[m] < ub)
      {
        if (s == e)
        {
          ub = (m + 1 <= l - 1) && arr[m + 1] <= ub ? m + 1 : m;
          break;
        }
        s = m + 1 > e ? m : m + 1;
      }
      if (arr[m] > ub)
      {
        if (s == e)
        {
          ub = m - 1;
          break;
        }
        e = m - 1 < s ? m : m - 1;
      }
    }
  }
  else
  {
    return 0;
  }

  times = ub - lb;
  return times > 0 ? times : 0;
}

int main()
{

  int t;
  cin >> t;

  for (int x = 0; x < t; x++)
  {
    int n;
    int times = 0;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < n - 2; i++)
    {
      for (int j = i + 1; j < n - 1; j++)

        times += findTimes(arr, i, j, n);
    }
    cout << "Case " << x + 1 << ": " << times << endl;
  }

  return 0;
}
