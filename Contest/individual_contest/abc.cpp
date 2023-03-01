#include <algorithm>
#include <iostream>

using namespace std;

void print(int *arr, char ch) {

  sort(arr, arr + 3);

  switch (ch) {
  case 'A':
    cout << arr[0] << " ";
    break;
  case 'B':
    cout << arr[1] << " ";
    break;
  case 'C':
    cout << arr[2] << " ";
    break;
  }
}

int main() {
  int val[3];
  string str;

  cin >> val[0] >> val[1] >> val[2];
  cin.ignore();
  cin >> str;

  print(val, str[0]);
  print(val, str[1]);
  print(val, str[2]);

  return 0;
}
