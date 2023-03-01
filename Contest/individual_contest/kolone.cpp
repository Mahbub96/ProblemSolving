#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
string res;
int main() {

  int x, y;
  string a, b;

  cin >> x >> y >> a >> b;

  int t;
  cin >> t;
  sort(a.rbegin(), a.rend());

  res = a + b;

  for (int i = 1; i < x + y - 1; i++) {
    if (i == 1) {
      swap(res[x - i], res[x]);
      else if (i % 2) {
      }
      else {
      }
    }

    cout << res;

    return 0;
  }
