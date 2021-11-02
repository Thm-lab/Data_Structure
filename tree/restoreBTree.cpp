/*
 *
 
 * Restore the binary tree
 * 还原二叉树（先序遍历和中序遍历）
 * 给出一个二叉树的先序遍历和中序遍历将其构建为一个二叉树然后后序遍历
 * 二叉树的存储结构为孩子链表
 * 已通过码图测试
 * 
 * 
*/
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

typedef struct BTREE {
  char data;
  struct BTREE* left;
  struct BTREE* right;
} BTNode, *BTree;

BTNode* creatBTree(string pre, string in);
void postOrder(BTree root);
bool checkSame(string stringA, string stringB);

int main() {
  string pre;
  string in;
  cin >> pre;
  cin >> in;
  if (pre.length() == in.length() && checkSame(pre, in)) {
    BTree root = creatBTree(pre, in);
    postOrder(root);
  } else {
    cout << "error";
  }
  return 0;
}

// 根据先序遍历和中序遍历构建二叉树
BTNode* creatBTree(string pre, string in) {
  if (pre.length() == 0 && in.length() == 0) {
    return NULL;
  }
  if (pre.length() == 1 && in.length() == 1) {
    BTNode* node = new BTNode;
    node->data = pre[0];
    node->left = node->right = NULL;
    return node;
  }

  BTNode* root = new BTNode;
  root->data = pre[0];

  int rootIndex = in.find(pre[0]);

  int leftTreeLength = rootIndex;
  int rightTreeLength = in.length() - rootIndex - 1;

  string leftTreeIn = in.substr(0, leftTreeLength);
  string rightTreeIn = in.substr(rootIndex + 1, rightTreeLength);

  string leftTreePre = pre.substr(1, leftTreeLength);
  string rightTreePre = pre.substr(leftTreeLength + 1, rightTreeLength);

  // cout << "leftTreePre: " << leftTreePre << endl;
  // cout << "rightTreePre: " << rightTreePre << endl;
  // cout << "leftTreeIn: " << leftTreeIn << endl;
  // cout << "rightTreeIn: " << rightTreeIn << endl;

  root->left = creatBTree(leftTreePre, leftTreeIn);
  root->right = creatBTree(rightTreePre, rightTreeIn);
  return root;
}

// 后序遍历
void postOrder(BTree root) {
  if (root != NULL) {
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data;
  }
}

// 判断输入的字符串是否是同一堆字符的不同排序
bool checkSame(string stringA, string stringB) {
  sort(stringA.begin(), stringA.end());
  sort(stringB.begin(), stringB.end());
  return stringA == stringB;
}