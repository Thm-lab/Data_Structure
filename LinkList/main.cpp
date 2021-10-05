#include <array>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include "LinkList.h"

class Person {
 private:
  string name;
  string phonenumber;
  string address;

 public:
  // constructor
  Person() : Person("Defalut", "18194080325", "UESTC") {}  // default contact
  Person(string name, string phonenumber, string address)
      : name{name}, phonenumber{phonenumber}, address{address} {}

  auto getName() { return name; }
  auto getPhoneNumber() { return phonenumber; }
  auto getAddress() { return address; }
  void setName(string name) { this->name = name; }
  void setPhoneNumber(string phonenumber) { this->phonenumber = phonenumber; }
  void setAddress(string address) { this->address = address; }
  string to_String() { return (name + " " + phonenumber + " " + address); }
  // destructor
  ~Person() {}
};


using namespace std;
template <typename T>
int LinkList<T>::numberOfList = 0;

int main() {
  LinkList<string> list;
  list.LinkInsert(new Node<string>("Hello"));
  list.LinkInsert(new Node<string>("World"));
  list.LinkInsert(new Node<string>("!"));
  list.print();
  cout << (list.LinkFind("World") != nullptr ? list.LinkFind("World")->data
                                             : "not found")
       << endl;
  return 0;
}