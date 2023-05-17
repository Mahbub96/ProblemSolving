#include <bits/stdc++.h>
#include <complex>

using namespace std;

/*
 * Complete the 'funnyString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string funnyString(string s) {
  unsigned int l = s.length();
  bool isFunny = true;

  for (unsigned int i = 0; i < l - 2; i++) {
    if (abs(s[i] - s[i + 1]) == abs(s[l - i - 1] - s[l - i - 2]))
      continue;
    else {
      isFunny = false;
      break;
    }
  }

  return isFunny ? "Funny" : "Not Funny";
}

int main() {

  int n;
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    string s;
    getline(cin, s);

    string result = funnyString(s);

    cout << result << "\n";
  }

  return 0;
}
