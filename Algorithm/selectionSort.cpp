#include <iostream>

using namespace std;
// n + n-1 + n-2 + n-3 + .. + 3 + 2 + 1
void selectionSort(int *arr, int len) {

  for (int i = 0; i < len; i++) {

    int minValue = arr[i];
    int minInd = -1;

    for (int j = i + 1; j < len; j++) {

      if (minValue > arr[j]) {
        minValue = arr[j];
        minInd = j;
      }
    }

    if (minInd != -1) {
      int temp = arr[i];
      arr[i] = arr[minInd];
      arr[minInd] = temp;
    }
  }
}

int main() {

  int arr[] = {64, 25, 12, 22, 11};

  selectionSort(arr, 5);

  for (int i = 0; i < 5; i++) {
    cout << arr[i] << ",";
  }
  return 0;
}
