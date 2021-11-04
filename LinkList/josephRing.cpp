/*
 *
 *
 * josephRing 约瑟夫游戏
 * 现在有N个人，只能剩余K个人，M为间隔人数
 * 现在通过数数来淘汰人
 * 每当数到M+1，该人即淘汰
 * 因此采用循环链表或循环数组（通过对index取模实现）
 * 主要功能通过一开始的if else里的else实现
 * if和else if是为了实现傻逼码图的输入（毫无逻辑，实际运用基本不用管）
 * 
 * 
 */




#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void print(Node* header) {
  Node* p = header->next;
  while (p) {
    if (p->next != NULL) {
      cout << p->data << ",";
    } else {
      cout << p->data;
    }
    p = p->next;
  }
}

void deleteNode(Node* header, int data) {
  Node* p = header->next;
  if (p->data == data) {
    header->next = p->next;
    Node* temp = header->next;
    while ((temp->next)->data > temp->data) {
      temp = temp->next;
    }
    temp->next = header->next;
    header->data--;
    delete p;
  } else {
    while ((p->next)->data != data) {
      p = p->next;
    }
    Node* temp = p->next;
    p->next = temp->next;
    delete temp;
    header->data--;
  }
}

void creatList(Node* header) {
  for (int i = 1; i <= header->data; i++) {
    Node* node = new Node;
    node->data = i;
    node->next = NULL;
    if (header->next == NULL) {
      header->next = node;
      continue;
    }
    Node* temp = (header->next);
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = node;

    // 构造循环链表
    if (node->data == header->data) {
      node->next = header->next;
    }
  }
}

int main() {
  int N, K, M;
  int ret = scanf("%d %d %d", &N, &K, &M);
  // printf("%d %d %d", N, K, M);
  // printf("%d\n", ret);


  if (M < 0 || N == 0 || ret != 3 || N < K && N != 0) {
    printf("ERROR");
  } else if (K == 0) {
    printf("0");
  } else if (N == K && N != 0) {
    for (int i = 1; i <= N; i++) {
      if (i != N) {
        printf("%d,", i);
      } else {
        printf("%d", i);
      }
    }
  } else {
    Node* header = new Node;
    header->data = N;
    header->next = NULL;

    // 创建链表
    creatList(header);

    // 开始删人
    int count = 1;
    Node* p = header->next;
    while (header->data != K) {
      if (count == M + 1) {
        int data = p->data;
        p = p->next;
        count = 1;
        deleteNode(header, data);
      }
      p = p->next;
      count++;
    }

    // 改回单链表
    p = header->next;
    while ((p->next)->data > p->data) {
      p = p->next;
    }
    p->next = NULL;

    // 输出单链表
    print(header);
  }
  return 0;
}