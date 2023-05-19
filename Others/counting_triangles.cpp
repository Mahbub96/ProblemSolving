#include <algorithm>
#include <iostream>

using namespace std;

class Bounds {
public:
  int ub;
  int lb;
};

Bounds find_bounds(int *arr, int a, int b, int l) {

  Bounds bound;

  return bound;
}

int main() {
  int t;
  cin >> t;

  for (int x = 0; x < t; x++) {
    int n;
    int times = 0;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
      int a = arr[i];
      for (int j = i + 1; j < n; j++) {
        int b = arr[j];

        for (int k = j + 1; k < n; k++) {
          int c = arr[k];
          if ((a + b) > c && (b + c) > a && (c + a) > b) {
            times++;
          }
        }
      }
    }
    cout << "Case " << x + 1 << ": " << times << endl;
  }
  return 0;
}
