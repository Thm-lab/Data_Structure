/**
 * 
 * create by Thm 2021-10-5 13:39
 * this is a template class for a data constructure
 * LinkList
 * After the test,it is useful to storage type int/double/char/string
 * but it failed to realize self-defined class
 * 
 * */
#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node {
 public:
  T data;
  Node<T>* next;
  Node() {}
  Node(T data) {
    this->data = data;
    this->next = nullptr;
  }
};

template <typename T>
class LinkList {
 private:
  Node<T>* header;
  Node<T>* tail;
  static int numberOfList;

 public:
  // constructor
  LinkList();
  // destructor
  ~LinkList();
  // get size of list
  int LinkSize();
  // insert an element to the end
  void LinkInsert(Node<T>* node);
  // delete by value
  void LinkDelete(T data);
  // find Node by value
  Node<T>* LinkFind(T data);
  // print for test
  void print() {
    Node<T>* p = header->next;
    cout << "list's size is :" << numberOfList << endl;
    while (p) {
      cout << p->data << endl;
      p = p->next;
    }
  }
};
template <typename T>
LinkList<T>::LinkList() {
  header = new Node<T>;
  tail = header;
}
template <typename T>
LinkList<T>::~LinkList() {
  if (header != tail) {
    Node<T>* p = header->next;
    delete header;
    header = nullptr;
    while (p) {
      Node<T>* temp = p->next;
      delete p;
      p = temp;
    }
  } else {
    delete header;
    header = nullptr;
  }
}
template <typename T>
int LinkList<T>::LinkSize() {
  return header->data;
}
template <typename T>
void LinkList<T>::LinkInsert(Node<T>* node) {
  if (header == tail) {
    tail = node;
    header->next = node;
  } else {
    tail->next = node;
    tail = node;
  }
  numberOfList++;
}
template <typename T>
void LinkList<T>::LinkDelete(T data) {
  Node<T>* p = header;
  while (p->next) {
    if (p->next->data == data) {
      Node<T>* temp = p->next;
      p->next = temp->next;
      if (temp == tail) {
        tail = p;
      }
      delete temp;
      numberOfList--;
      return;
    }
    p = p->next;
  }
  if (p == tail) {
    cout << "Delete failed: not find element" << endl;
  }
}
template <typename T>
Node<T>* LinkList<T>::LinkFind(T data) {
  Node<T>* p = header;
  while (p) {
    if (p->data == data) {
      return p;
    }
    p = p->next;
  }
  cout << "Find failed: not find element" << endl;
  return nullptr;
}