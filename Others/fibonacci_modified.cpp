#include <cmath>
#include <iostream>

using namespace std;

long long int fibonacci(int n) {
  if (n == 1)
    return 0;
  if (n == 2)
    return 1;

  return fibonacci(n - 2) + pow(fibonacci(n - 1), 2);
}

int main() {
  for (int i = 0; i < 10; i++) {

    cout << "Fibonacci : " << i + 1 << " : " << fibonacci(i + 1) << endl;
  }
  return 0;
}
