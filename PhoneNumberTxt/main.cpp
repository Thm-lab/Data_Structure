#define _CRT_SECURE_NO_DEPRECATE
#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
  char name[100];
  char pinyin[120];
  char phonenumber[20];
  char location[100];
  struct Person* next;
} Person;

typedef struct Header {
  int length;
  Person* first;
} Header;

void initialization();
void convert2Spell(Person* person);
void getperson(Person* person);
void printperson(Person* person);
void addperson(Header* header);
Person* findPrenode(Header* header, Person* person);
Person* findNextnode(Header* header, Person* person);
void sortByphonenumber(Header* header);
Person* findperson(Header* header);
void changeperson(Header* header);
void deleteperson(Header* header);
void displayperson(Header* header);
void releaseperson(Header* header);

void initialization() {
  printf("---   欢迎使用通讯录！  ---\n");
  printf("---按键1：查询联系人信息---\n");
  printf("---按键2：添加新的联系人---\n");
  printf("---按键3：删除已有联系人---\n");
  printf("---按键4：更改联系人信息---\n");
  printf("---按键5：显示所有联系人---\n");
  printf("---按键6：退出通讯录程序---\n");
  printf("---    Powered by ...   ---\n");
}

void convert2Spell(Person* person) {
  // printf("我是name!!!!%s!!!!\n", person->name);
  // char name_1[20] = "张宇";
  Py_Initialize();
  // 运行两条简单python语句
  PyRun_SimpleString("import sys");
  PyRun_SimpleString("sys.path.append('./')");
  // 扩展sys路径到pip安装第三方包地址
  PyRun_SimpleString(
      "sys.path.append('C:/msys64/mingw64/lib/python3.9/site-packages')");
  // 导入模块
  PyObject* pModule = PyImport_ImportModule("convertCN2Spell");
  // 导入模块中的函数
  PyObject* pFunc = PyObject_GetAttrString(pModule, "convertCN2Spell");
  // 将输入参数转换为python数据类型
  PyObject* pArgs = PyTuple_New(1);
  PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", person->name));
  // 调用函数
  PyObject* pValue = PyObject_CallObject(pFunc, pArgs);
  if (PyErr_Occurred()) {
    PyErr_PrintEx(0);
    PyErr_Clear();
  }
  // 将返回字符串类型转换为c字符串类型
  char* result;
  PyArg_Parse(pValue, "s", &result);
  // printf("返回值：%s\n", result);
  strcpy(person->pinyin, result);
  // 释放
  Py_Finalize();
}

void getperson(Person* person) {
  printf("请输入联系人姓名：");
  // fflush(stdin);
  scanf("%s", person->name);
  printf("\n");
  // fflush(stdin);  //刷新标准输入缓冲区
  printf("请输入联系人电话号码：");
  scanf("%s", person->phonenumber);
  // fflush(stdin);  // fflush(stdin)刷新标准输入缓冲区
  printf("\n");
  printf("请输入联系人地址：");
  scanf("%s", person->location);
  // fflush(stdin);  // fflush(stdin)刷新标准输入缓冲区
  // convert2Spell(person);
}

void printperson(Person* person) {
  printf("联系人姓名：%s\n", person->name);
  printf("联系人电话号码：%s\n", person->phonenumber);
  printf("联系人地址：%s\n", person->location);
  printf("联系人姓名拼音：%s\n", person->pinyin);
  putchar('\n');
  // fflush(stdin);  // fflush(stdin)刷新标准输入缓冲区
}

void addperson(Header* header) {
  //尾插法插入新的联系人信息

  Person* temp;
  Person* contact;
  static Person* tail;  //定义tail指针，指向单链表结尾

  contact = (struct Person*)malloc(sizeof(Person));
  if (contact == NULL) {
    printf("内存分配失败\n");
    exit(1);
  }

  getperson(contact);

  // if (*person != NULL) {
  //   tail->next = contact;
  //   contact->next = NULL;
  // } else {
  //   *person = contact;
  //   contact->next = NULL;
  // }

  if (header->first) {
    tail->next = contact;
    contact->next = NULL;
    (header->length)++;
  } else {
    contact->next = NULL;
    header->first = contact;
    (header->length)++;
  }

  tail = contact;

  printf("添加成功!\n");
  fflush(stdin);
}

Person* findPrenode(Header* header, Person* person) {
  Person* temp;
  if (header) {
    if (person == header->first) {
      return NULL;
    }

    temp = header->first;
    while (temp->next != person) {
      temp = temp->next;
    }
    return temp;
  } else {
    printf("没有找到直接前驱!");
    return NULL;
  }
}

Person* findNextnode(Header* header, Person* person) {
  Person* temp;
  if (header) {
    if (person->next == NULL) {
      return NULL;
    }

    temp = header->first;
    while (temp != person) {
      temp = temp->next;
    }
    if (temp->next) {
      return temp->next;
    }
  } else {
    printf("没有找到直接后继!");
  }
}

void sortByphonenumber(Header* header) {
  Person* temp;
  Person* person;
  person = header->first;
  // printf("ok");
  while (person->next != NULL) {
    if (strcmp(person->phonenumber, (person->next)->phonenumber) >= 0) {
      // printf("ok1");
      Person* preNode;
      Person* nextNode;
      preNode = findPrenode(header, person);
      nextNode = findNextnode(header, person->next);
      //交换节点顺序
      // printf("ok2");

      if (preNode == NULL) {
        temp->next = (person->next)->next;
        header->first = person->next;
        (header->first)->next = person;
        person->next = temp->next;
        // printf("ok3");
        continue;
      }
      if (nextNode == NULL) {
        preNode->next = person->next;
        (preNode->next)->next = person;
        person->next = NULL;
        // printf("ok4");
        continue;
      }

      // temp = person;
      // printf("ok5");
      preNode->next = person->next;
      person->next = nextNode;
      (preNode->next)->next = person;
    }
  }

  // while ((person->next) != NULL) {
  //   // printperson(person);
  //   if (strcmp(person->phonenumber, (person->next)->phonenumber) >= 0) {
  //     //找到直接前驱和直接后继
  //     Person* preNode;
  //     Person* nextNode;
  //     // printf("ok1");
  //     preNode = findPrenode(header, person);
  //     nextNode = findNextnode(header, person->next);
  //     // printf("ok2");
  //     //交换节点顺序
  //     temp = person;
  //     preNode->next = person->next;
  //     person->next = nextNode;
  //     (preNode->next)->next = temp;
  //   }
  // }
}

Person* findperson(Header* header) {
  Person* findcontact;
  findcontact = header->first;
  char input[40];
  printf("请输入要查找关键词：");
  fflush(stdin);
  printf("1:姓名  2：电话号码 3：地址\n");
  fflush(stdin);
  printf("请输入：");
  fflush(stdin);
  int ch;
  scanf("%d", &ch);
  switch (ch) {
    case 1:
      scanf("%s", input);
      while (findcontact != NULL && strcmp(findcontact->name, input)) {
        findcontact = findcontact->next;
      }
      break;

    case 2:
      scanf("%s", input);
      while (findcontact != NULL && strcmp(findcontact->phonenumber, input)) {
        findcontact = findcontact->next;
      }
      break;

    case 3:
      scanf("%s", input);
      while (findcontact != NULL && strcmp(findcontact->location, input)) {
        findcontact = findcontact->next;
      }
      break;

    default:
      printf("请检查您的输入!");
      return NULL;
      break;
  }
  return findcontact;
}
void changeperson(Header* header) {
  Person* contact;
  char ch1, ch2, ch3;
  contact = findperson(header);
  if (contact == NULL) {
    printf("未查询到该联系人的信息！\n");
  } else {
    printf("已查询到该联系人信息！:\n");
    printperson(contact);  //这里之前写成void printperson
    printf("是否要修改联系人姓名？(Y/N)");
    scanf("%c", &ch1);
    fflush(stdin);  // fflush(stdin)刷新标准输入缓冲区，防止跳过第一个if语句
    if (ch1 == 'Y' || ch1 == 'y') {
      printf("请输入该联系人的姓名：");
      scanf("%s", contact->name);
      fflush(stdin);
      printf("联系人姓名更改成功！\n");
    }
    printf("是否要修改联系人电话号码？(Y/N)");
    scanf("%c", &ch2);
    fflush(stdin);
    if (ch2 == 'Y' || ch2 == 'y') {
      printf("请输入新的电话号码：");
      scanf("%s", contact->phonenumber);
      fflush(stdin);
      printf("联系人电话号码更改成功！\n");
    }
    printf("是否要修改联系人地址？(Y/N)");
    scanf("%c", &ch2);
    fflush(stdin);
    if (ch3 == 'Y' || ch3 == 'y') {
      printf("请输入新的电话号码：");
      scanf("%s", contact->location);
      fflush(stdin);
      printf("联系人地址更改成功！\n");
    }
  }
}

void deleteperson(Header* header) {
  Person* findcontact;
  Person* previous;
  Person* current;

  findcontact = findperson(header);
  if (findcontact == NULL) {
    printf("未查询到该联系人的信息！\n");
    printf("是否添加该人为联系人?是：请输入Y/y，否：请输入其他字符");
    char input;
    scanf("%c", &input);
    if (input == 'Y' || input == 'y') {
      addperson(header);
    } else {
      return;
    }
  } else {
    // printf("ok1");
    printperson(findcontact);
    Person* preNode = findPrenode(header, findcontact);
    Person* nextNode = findNextnode(header, findcontact);
    // printf("ok2"); //此处报错 怀疑find问题
    if (preNode && nextNode) {
      preNode->next = nextNode;
    } else if (preNode) {
      preNode->next = NULL;
    } else {
      header->first = nextNode;
    }
    // current = *person;
    // previous = NULL;

    // while (current != NULL && current != findcontact) {
    //   previous = current;
    //   current = current->next;
    // }

    // if (previous == NULL) {
    //   *person = current->next;
    // } else {
    //   previous->next = current->next;
    // }
    header->length--;
    printf("联系人%s删除成功！\n", findcontact->name);
  }
}

void displayperson(Header* header) {
  Person* current;
  current = header->first;

  while (current != NULL) {
    printperson(current);
    current = current->next;
  }

  printf("是否根据电话号码进行排序？\n");
  printf("是：请输入Y/y 否：请输入其他字符");
  char input;
  scanf("%c", &input);
  if (input == 'Y' || input == 'y') {
    sortByphonenumber(header);
    fflush(stdin);
    printf("排序成功");
  }
}

void releaseperson(Header* header) {
  Person* temp;
  Person* person = header->first;
  free(header);
  while (person != NULL) {
    temp = person;
    // ->优先级高于* ，记得加括号(*person)，不然出错。
    // *person = (*person)->next;
    free(temp);
    person = person->next;
  }
}

int main(void) {
  int ch;
  Person* person = NULL;
  Person* findcontact;
  Header* header;  //头指针
  header->first = NULL;
  header->length = 0;
  initialization();
  do {
    printf("\n请按以上数字键：");
    fflush(stdin);
    scanf("%d", &ch);
    switch (ch) {
      case 1:
        findcontact = findperson(header);
        if (findcontact == NULL) {
          printf("未查询到该联系人的信息！\n");
        } else {
          printperson(findcontact);
        }
        break;

      case 2:
        addperson(header);
        break;

      case 3:
        deleteperson(header);
        break;

      case 4:
        changeperson(header);
        break;

      case 5:
        printf("您的通讯录共有%d人\n", header->length);
        displayperson(header);
        break;

      case 6:
        printf("再见！\n");
        break;

      default:
        printf("请检查您的输入!\n");
        break;
    }
  } while (ch != 6);

  releaseperson(header);

  system("pause");
  return 0;
}
