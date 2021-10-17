/**
 *
 *BF为暴力检索字符串中子串出现的index 一个个字符比较
 *最坏时间复杂度为O(n*m)，n为原串长度m为子串长度 最好时间复杂度为O(m)
 *KMP为BF的简化算法 时间复杂度为O(m+n)
 *思想在于跳过部分不可能匹配的字段从而减少比较原串和子串的次数
 *
 **/
#include <iostream>
#include <string>

using namespace std;

int BF(string s1, string s2);
int KBP(string s1, string s2);
void makeNext(string s, int next[]);

int main() {
  string s1 = "hrtjhteryujouldfyhtr";
  string s2 = "ould";
  cout << "BF: " << BF(s1, s2) << endl;
  cout << "KBP: " << KBP(s1, s2) << endl;
  return 0;
}

int BF(string s1, string s2) {
  int i = 0, j = 0;
  while (i < s1.length() && j < s2.length()) {
    if (s1[i] == s2[j]) {
      i++;
      j++;
    } else {
      i = i - j + 1;
      j = 0;
    }
  }
  if (j >= s2.length()) {
    return i - j;
  } else {
    return -1;
  }
}

int KBP(string s1, string s2) {
  int i = 0, j = 0;
  // next数组为最大公共前后缀的长度 例如abcab的next为2，最大公共前后缀为ab
  int next[7];
  // 用dp(动态规划)求next数组
  makeNext(s2, next);
  // KMP比较
  while (i < s1.length() && j < s2.length()) {
    if (s1[i] == s2[j]) {
      i++;
      j++;
    } else {
      i++;
      j = j - next[j];
    }
  }
  if (j >= s2.length()) {
    return i - j;
  } else {
    return -1;
  }
}

// 生成next数组
void makeNext(string s, int next[]) {
  int q, k;
  int m = s.length();
  next[0] = 0;
  for (q = 1, k = 0; q < m; ++q) {
    while (k > 0 && s[q] != s[k])
      k = next[k - 1];
    if (s[q] == s[k]) {
      k++;
    }
    next[q] = k;
  }
}