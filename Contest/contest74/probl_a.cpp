#include <iostream>
#define ll long long

using namespace std;

bool findSame(ll int *a, int s) {
  unsigned short x = a[0];
  for (int i = 1; i < s; i++) {
    if (x == a[i])
      continue;
    else
      return false;
  }
  return true;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int s;
    cin >> s;
    ll int arr[s];
    for (int i = 0; i < s; i++) {
      cin >> arr[i];
    }

    bool isSame = findSame(arr, s);
    bool isOdd = s % 2;

    if ((isOdd && isSame) || (!isOdd && !isSame))
      cout << "Mrinalini" << endl;

    else if ((isOdd && !isSame) || (!isOdd && isSame))
      cout << "Kadambari" << endl;
  }

  return 0;
}
