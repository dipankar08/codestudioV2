/***************************************************
 * Title : ReverseWordsInaSentense
 * Author: Dipankar Dutta
 ****************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void reverse(char *a, char *b) {
  while (a < b) {
    char temp = *a;
    *a = *b;
    *b = temp;
    a++;
    b--;
  }
}

void ReverseWordsInaSentense(char *s) {
  char *word_begin = s;
  char *temp = s;
  while (*temp) {
    temp++;
    if (*temp == '\0') {
      reverse(word_begin, temp - 1);
    } else if (*temp == ' ') {
      reverse(word_begin, temp - 1);
      word_begin = temp + 1;
    }
  }
  reverse(s, temp - 1);
}

int main() {
  char s[] = "  I   Love Computer Science  ";
  ReverseWordsInaSentense(s);
  cout << s << endl;
}
