/**
 *
 * shellSort parament introduction
 * shellSort is named by Descending incremental sort algorithm
 * int a[] is that array which is waiting sort
 * left is the starting
 * right is the ending
 * gap is incremental which is decreaing
 * Shell: gap/=2
 * Hibbard: gap = 2^k - 1
 *
 */
#include <math.h>
#include <array>
#include <cmath>
#include <iostream>

using namespace std;

enum { Shell, Hibbard };

void shellSort(int a[], int left, int right, int gap);
void getGap(int gap[], int len, int MODE);
void insertSort(int a[], int left, int right, int gap);

int main() {
  int a[] = {
      3, 1, 2, 5, 4, 6, 9, 7, 10, 8,
  };
  int b[] = {
      3, 1, 2, 5, 4, 6, 9, 7, 10, 8,
  };
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
  shellSort(a, 0, (sizeof(a) / sizeof(a[0])) - 1, Shell);
  shellSort(b, 0, (sizeof(b) / sizeof(b[0])) - 1, Hibbard);
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    cout << a[i] << " ";
  }
  return 0;
}

void shellSort(int a[], int left, int right, int MODE) {
  int len = right - left + 1;
  int gap[len];
  getGap(gap, len, MODE);
  int i = 0;
  while (gap[i]) {
    insertSort(a, left, right, gap[i]);
    i++;
  }
}

void getGap(int gap[], int len, int MODE) {
  switch (MODE) {
    case Shell: {
      int k = 0;
      for (int i = len / 2; i >= 1; i /= 2) {
        gap[k] = i;
        k++;
      }
      gap[k] = 0;
      break;
    }
    case Hibbard: {
      int h[len] = {0};
      int k = 0;
      while (h[k - 1] < len) {
        h[k] = pow(2, k + 1) - 1;
        k++;
      }
      int i = 0;
      while (h[i + 1]) {
        i++;
      }
      for (int j = i; j >= 0; j--) {
        gap[i - j] = h[j];
      }
      gap[i + 1] = 0;
      break;
    }
  }
}

void insertSort(int a[], int left, int right, int gap) {
  int i = left + gap;
  for (; i <= right; i++) {
    int insert = a[i];
    int j = i - gap;
    while (a[j] > insert && (j >= left)) {
      a[j + gap] = a[j];
      j -= gap;
    }
    a[j + gap] = insert;
  }
}