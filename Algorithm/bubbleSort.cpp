#include <iostream>

void bubbleSort(int *arr, int len) {

  for (int i = 0; i <= len; i++) {
    for (int j = 0; j < len - 1; j++) {

      if (arr[j] > arr[j + 1]) {

        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {

  int arr[] = {5, 3, 4, 2, 1};

  bubbleSort(arr, 5);

  for (int i = 0; i < 5; i++) {
    std::cout << arr[i] << ",";
  }
  return 0;
}
