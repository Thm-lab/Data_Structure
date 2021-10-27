/**
 *
 * quickSort parament introduction
 * int a[] is that array which is waiting sort
 * left is the starting
 * right is the ending
 *
 */
#include <array>
#include <cmath>
#include <iostream>

using namespace std;

void quickSort(int a[], int left, int right);

int main() {
  int a[] = {
      3, 1, 2, 5, 4, 6, 9, 7, 10, 8,
  };
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
  quickSort(a, 0, (sizeof(a) / sizeof(a[0])) - 1);
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    cout << a[i] << " ";
  }
  return 0;
}

void quickSort(int a[], int left, int right) {
  // 错误判断
  if (left >= right) {
    return;
  }
  // 用最左边元素当基准
  int pivot = a[left];
  int i = left, j = right;
  while (i != j) {
    // 左基准的情况下 一定是右标兵先移动
    while (a[j] >= pivot && i < j) {
      j--;
    }
    while (a[i] <= pivot && i < j) {
      i++;
    }
    swap(a[i], a[j]);
  }
  // 把pivot放到左边比它小 右比它大的地方
  swap(a[left], a[i]);
  // 对左右段分别递归
  quickSort(a, left, i - 1);
  quickSort(a, i + 1, right);
}