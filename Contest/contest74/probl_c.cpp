#include <iostream>
#define ll long long

using namespace std;

double oddSum(ll int *arr, ll int s) {
  ll int res = 0;
  for (int i = 0; i < s - 1; i += 2) {
    res += arr[i + 1];
    res %= 1000000007;
  }
  return res;
}

int main() {
  int s, op;
  cin >> s >> op;
  ll int arr[s];

  for (int i = 0; i < s; i++) {
    cin >> arr[i];
  }
  while (op--) {
    int ind, val;
    cin >> ind >> val;

    arr[ind - 1] = val;
    cout << oddSum(arr, s) << endl;
  }

  return 0;
}
