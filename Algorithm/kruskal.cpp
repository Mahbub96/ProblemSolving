#include <iostream>
#include <vector>

using namespace std;

void show(vector<vector<int>> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << "node : " << i << " neighbours : ";
    for (int j = 0; j < v[i].size(); j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> v(n);

  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;

    for (int j = 0; j < p; j++) {

      int temp;
      cin >> temp;

      v[i].push_back(temp);
    }
  }

  show(v);

  return 0;
}
