/***************************************************
 * Title : Remove dups using Loop.
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
using namespace std;
void removeDup(ListNode *start) {
  ListNode *ptr1 = start;
  while (ptr1 != NULL && ptr1->next != NULL) {
    ListNode *ptr2 = ptr1;
    while (ptr2->next != NULL) {
      if (ptr1->val == ptr2->next->val) {
        ListNode *dup = ptr2->next;
        ptr2->next = ptr2->next->next;
        delete (dup);
      } else {
        ptr2 = ptr2->next;
      }
    }
    ptr1 = ptr1->next;
  }
}

int main() {
  ListNode *list = createList({1, 1, 2, 2, 3, 3});
  removeDup(list);
  printList(list); // 1->2->3
  return 0;
}
