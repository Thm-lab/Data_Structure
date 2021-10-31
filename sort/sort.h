/**
 * 
 * 
 * sort.h paraments introduction
 * int a[] is that array which is waiting sort
 * left is the start index
 * right is the end index
 * 
 * 
 * Especially, shellSort has another parament:MODE
 * MODE can decide which mode of shellSort will choose to create a sequence of gap
 * Shell: gap/=2
 * Hibbard: gap = 2^k - 1
 * 
 * 
 */


#pragma once

void bubbleSort(int a[], int left, int right) {
  for (int i = left; i < right; i++) {
    for (int j = 0; j < (right - left + 1) - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
      }
    }
  }
}
void countingSort(int a[], int left, int right) {
  int max = a[left];
  int min = a[left];
  for (int i = 0; i < right - left + 1; i++) {
    max = std::max(a[i], max);
    min = std::min(a[i], min);
  }
  int temp[max - min + 1];
  memset(temp, 0, sizeof(temp));
  for (int i = left; i <= right; i++) {
    temp[a[i] - min]++;
  }
  for (int i = 1; i < max - min + 1; i++) {
    temp[i] += temp[i - 1];
  }
  for (int i = max - min; i >= 0; i--) {
    a[left + temp[i] - 1] = (i + min);
  }
}
void heapSort(int a[], int left, int right) {
  for (int i = right; i > left - 1; i--) {
    buildMaxHeap(a, left, i);
    swap(a[left], a[i]);
  }
}
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
      root = child + 1;
    }
  }
}
void insertSort(int a[], int left, int right) {
  int i = left + 1;
  for (; i <= right; i++) {
    int insert = a[i];
    int j = i - 1;
    while (a[j] > insert && (j >= left)) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = insert;
  }
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
void selectSort(int a[], int left, int right) {
  int i, j;
  for (i = left; i < right; i++) {
    int min = a[i];
    int min_index = i;
    for (j = i + 1; j <= right; j++) {
      if (a[j] < min) {
        min = a[j];
        min_index = j;
      }
    }
    int temp = a[i];
    a[i] = min;
    a[min_index] = temp;
  }
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
