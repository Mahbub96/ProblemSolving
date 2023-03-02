#include <iostream>

using namespace std;

int main() {

  int aLen, bLen, t;
  string a, b, s;

  cin >> aLen >> bLen;
  cin.ignore();
  cin >> a >> b;
  cin.ignore();
  cin >> t;

  for (int i = aLen - 1; i > -1; i--) {
    s.push_back(a[i]);
  }
  s += b;
  int l = aLen + bLen;

  char res[l] = {};
  if (t == 0) {
    cout << s;
    return 0;
  }
  // for right line
  for (int i = 0; i < bLen; i++) {
    int ind = (aLen + i) - t + i;

    if (ind < 0)
      ind = 0;
    if (ind >= l)
      ind = l - 1;

    // find empty cell
    for (int j = ind; j < l; j++) {
      if (res[j] == '\0') {
        res[j] = s[aLen + i];
        break;
      }
    }
  }

  // for left line
  for (int i = 0; i < aLen; i++) {

    int ind = (aLen - i - 1) + t - i;
    ind = ind > (l - 1) ? l - 1 : ind;
    ind = ind < 0 ? 0 : ind;

    // find empty cell
    for (int j = ind; j > -1; j--) {
      if (res[j] == '\0') {
        res[j] = s[aLen - i - 1];
        break;
      }
    }
  }

  for (int i = 0; i < l; i++) {
    cout << res[i];
  }
  return 0;
}
