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
  if (left >= right) {
    return;
  }
  int pivot = a[left];
  int i = left, j = right;
  while (i != j) {
    while (a[j] >= pivot && i < j) {
      j--;
    }
    while (a[i] <= pivot && i < j) {
      i++;
    }
    swap(a[i], a[j]);
  }
  swap(a[left], a[i]);
  quickSort(a, left, i - 1);
  quickSort(a, i + 1, right);
}