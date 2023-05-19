#include <algorithm>
#include <iostream>

using namespace std;

class Bounds
{
public:
  int ub;
  int lb;
};

Bounds find_bounds(int *arr, int s, int e, int &a, int &b, int &l)
{

  Bounds bound;

  int lowb = abs(arr[a] - arr[b]) + 1;
  int upb = (arr[a] + arr[b]) - 1;

  cout << "lb:" << lowb << ",ub:" << upb << endl;

  if (lowb > b)
  {
    bound.lb = b + 1;
  }

  if (upb > b)
  {

    while (s <= e)
    {

      int mid = (s + e) / 2;

      cout << "s:" << s << ",e:" << e << ",upb:" << upb << endl;
      cout << "ind : " << mid << "," << arr[mid] << endl;
      if (arr[mid] == upb)
      {

        bound.ub = mid;
        break;
      }

      if (arr[mid] < upb)
      {
        if (s == e)
        {
          bound.ub = mid + 1;
          cout << "last step first" << endl;
          break;
        }
        s = mid + 1;
      }

      if (arr[mid] > upb)
      {

        if (s == e)
        { // in case of last step
          cout << "last step" << endl;
          bound.ub = mid - 1;
          break;
        }
        e = mid;
      }
    }

    if (upb < e)
    {
    }
  }
  return bound;
}
int main()
{
  /*
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
        int a = arr[i];
        for (int j = i + 1; j < n - 1; j++)
        {
          int b = arr[j];

          Bounds bs = find_bounds(arr, j + 1, n, a, b, n);
          int temp = bs.ub - bs.lb;
          cout << bs.lb << " , " << bs.ub << endl;
          cout << "temp : " << temp << endl;
          times = temp > 0 ? temp : 0;
        }
      }
      cout << "Case " << x + 1 << ": " << times << endl;
    }
  */

  int arr[] = {1, 2, 3, 4, 5, 6};
  int a = 0;
  int b = 1;
  int l = 6;

  Bounds bs = find_bounds(arr, b + 1, l, a, b, l);
  cout << (bs.ub - bs.lb) + 1 << endl;
  cout << bs.lb << " , " << bs.ub << endl;

  return 0;
}
