/**
 *
 * mergeSort(recursion) parament introduction
 * int a[] is that array which is waiting sort
 * left is the starting
 * right is the ending
 *
 */
#include <array>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

void mergeSort(int a[], int left, int right);
void merge(int a[], int left, int mid, int right);

int main() {
  int a[] = {
      3, 1, 2, 5, 4, 6, 9, 7, 10, 8,
  };
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
  mergeSort(a, 0, (sizeof(a) / sizeof(a[0])) - 1);
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    cout << a[i] << " ";
  }
  return 0;
}

void mergeSort(int a[], int left, int right) {
  if (left == right) {
    return;
  }
  int mid = (left + right) / 2;
  mergeSort(a, left, mid);
  mergeSort(a, mid + 1, right);
  merge(a, left, mid, right);
}

// 将两个有序的数组合并到一个数组
void merge(int a[], int left, int mid, int right) {
  int* temp = new int[right - left + 1];
  int i = left;
  int j = mid + 1;
  int k = 0;
  while (i <= mid && j <= right)
    temp[k++] = a[i] <= a[j] ? a[i++] : a[j++];
  while (i <= mid)
    temp[k++] = a[i++];
  while (j <= right)
    temp[k++] = a[j++];
  memcpy(&(a[left]), temp, (right - left + 1) * sizeof(int));
  delete[] temp;
}