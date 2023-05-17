#include <cmath>
#include <stdio.h>

#define ll unsigned long long

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    ll a, r, n;
    scanf("%lld %lld %lld", &a, &r, &n);

    // ll res = a * (r ^ n - 1) / (r - 1);
    ll res = (a * (pow(r, n) - 1)) / (r - 1);
    printf("%lld", res % 1000003);
  }
  return 0;
}
