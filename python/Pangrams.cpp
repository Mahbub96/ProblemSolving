#include <iostream>
#include <map>

using namespace std;

int main() {

  map<string, string> m;

  string s;
  cin >> s;

  if (s.length()) {
    cout << "not pangram";
    return 0;
  }

  return 0;
}
