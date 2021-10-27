/**
 * 
 * insertSort parament introduction
 * int a[] is that array which is waiting sort
 * left is the starting
 * right is the ending
 * 
*/
#include <array>
#include <cmath>
#include <iostream>

using namespace std;

void insertSort(int a[], int left, int right);

int main() {
  int a[] = {
      3, 1, 2, 5, 4, 6, 9, 7, 10, 8,
  };
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
  insertSort(a, 0, (sizeof(a) / sizeof(a[0])) - 1);
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    cout << a[i] << " ";
  }
  return 0;
}

void insertSort(int a[], int left, int right) {
  int i = left + 1;
  for (; i <= right; i++) {
    int insert = a[i];
    int j = i - 1;
    // 用while把a[i-1]的元素往后移动 直到一个比a[i]小的 然后把insert放到这个元素后面
    while (a[j] > insert && (j >= left)) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = insert;
  }
}