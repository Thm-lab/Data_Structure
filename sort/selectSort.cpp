/**
 *
 * selectSort parament introduction
 * int a[] is that array which is waiting sort
 * left is the starting
 * right is the ending
 *
 */
#include <array>
#include <cmath>
#include <iostream>

using namespace std;

void selectSort(int a[], int left, int right);

int main() {
  int a[] = {
      3, 1, 2, 5, 4, 6, 9, 7, 10, 8,
  };
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
  selectSort(a, 0, (sizeof(a) / sizeof(a[0])) - 1);
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    cout << a[i] << " ";
  }
  return 0;
}

void selectSort(int a[], int left, int right) {
  int i, j;
  for (i = left; i < right; i++) {
    int min = a[i];
    int min_index = i;
    // 找到所有的元素中最小项
    for (j = i + 1; j <= right; j++) {
      if (a[j] < min) {
        min = a[j];
        min_index = j;
      }
    }
    // 把第n小项放到left+i的位置
    int temp = a[i];
    a[i] = min;
    a[min_index] = temp;
  }
}