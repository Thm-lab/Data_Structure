/**
 *
 * heapSort parament introduction
 * int a[] is that array which is waiting sort
 * left is the starting
 * right is the ending
 *
 */
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>

using namespace std;

void buildMaxHeap(int a[], int left, int right);
void heapSort(int a[], int left, int right);

int main() {
  int a[] = {
      3, 1, 2, 5, 4, 6, 9, 7, 10, 8,
  };
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
  heapSort(a, 0, 10);
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
    cout << a[i] << " ";
  }
}

// 每次把大顶堆的根节点（最大的）放到序列最后一个 然后在n-1的序列重新生成大顶堆
void heapSort(int a[], int left, int right) {
  for (int i = right; i > left - 1; i--) {
    buildMaxHeap(a, left, i);
    swap(a[left], a[i]);
  }
}

// 创建一个大顶堆
void buildMaxHeap(int a[], int left, int right) {
  int root = right / 2;
  int child = right;
  for (; root >= left; root--) {
    if (root == 0) {
      child = 1;
    } else {
      child = root * 2;
    }
    if ((child + 1 <= right) && (a[child] < a[child + 1])) {
      child = child + 1;
    }
    if ((a[root] < a[child]) && (child <= right)) {
      swap(a[root], a[child]);
      // 交换一个对child点进行检测是否符合大顶堆特点
      root = child + 1;
    }
  }
}