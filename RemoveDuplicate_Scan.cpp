/***************************************************
 * Title : Remove dups using Scan
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
#include <unordered_set>
using namespace std;
void removeDup(ListNode *start) {
  ListNode *cur = start;
  while (cur) {
    while (cur->next && cur->val == cur->next->val) {
      ListNode *dup = cur->next;
      cur->next = cur->next->next;
      delete (dup);
    }
    cur = cur->next;
  }
}

int main() {
  ListNode *list = createList({1, 1, 2, 2, 3, 3});
  removeDup(list);
  printList(list); // 1->2->3
  return 0;
}
