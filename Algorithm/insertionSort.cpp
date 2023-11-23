#include <iostream>

void insertionSort(int *arr, int len) {
  for (int i = 0; i < len; i++) {

    int j = i + 1;
    while (j--) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main() {
  int arr[] = {6, 2, 1, 3, 4};

  insertionSort(arr, 5);
  return 0;
}
