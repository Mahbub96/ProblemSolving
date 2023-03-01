#include <algorithm>
#include <iostream>

using namespace std;

int main() {

  int x, y;
  string a, b, s;
  int t;

  cin >> x >> y >> a >> b >> t;

  sort(a.rbegin(), a.rend());

  s = a + b;
  int aLen = a.length();
  int bLen = b.length();

  int diff = abs(aLen - bLen);

  int l = t > aLen + bLen ? aLen + bLen - 1 : t;

  int fp = aLen - 1;
  for (int i = 0; i < l; i++) {

    for (int j = 0, k = 0; j <= i; j++, k += 2) {
      swap(s[fp + k], s[fp + 1 + k]);
    }
    --fp;
  }
  cout << s;

  return 0;
}
