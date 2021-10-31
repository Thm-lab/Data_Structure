/**
 *
 * countingSort parament introduction
 * int a[] is that array which is waiting sort
 * left is the starting
 * right is the ending
 *
 */
#include <array>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

void countingSort(int a[], int left, int right);

int main() {
  int a[] = {
      3, 1, 2, 5, 4, 6, 9, 7, 10, 8,
  };
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
  countingSort(a, 0, (sizeof(a) / sizeof(a[0])) - 1);
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    cout << a[i] << " ";
  }
  return 0;
}

void countingSort(int a[], int left, int right) {
  int max = a[left];
  int min = a[left];
//   找到最大值和最小值来确定存储数组的大小
  for (int i = 0; i < right - left + 1; i++) {
    max = std::max(a[i], max);
    min = std::min(a[i], min);
  }
  int temp[max - min + 1];
  memset(temp, 0, sizeof(temp));
//   统计每个数出现的次数
  for (int i = left; i <= right; i++) {
    temp[a[i] - min]++;
  }
//   让每个数字找到自己对应的下标
  for (int i = 1; i < max - min + 1; i++) {
    temp[i] += temp[i - 1];
  }
//   倒序把数放到其下标 正序不能处理负数 所以一定要倒序
  for (int i = max - min; i >= 0; i--) {
    a[left + temp[i] - 1] = (i + min);
  }
}