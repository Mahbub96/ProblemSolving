#include <iostream>

using namespace std;

string s;
int x = 1;

void move(char ch) {

  switch (ch) {
  case 'A':
    if (x == 1)
      x = 2;
    else if (x == 2)
      x = 1;
    break;
  case 'B':
    if (x == 2)
      x = 3;
    else if (x == 3)
      x = 2;
    break;

  case 'C':
    if (x == 1)
      x = 3;
    else if (x == 3)
      x = 1;
    break;
  }
}

int main() {

  cin >> s;

  int n = s.length();
  for (int i = 0; i < n; i++) {
    move(s[i]);
  }
  cout << x;
  return 0;
}
