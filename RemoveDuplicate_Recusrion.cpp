/***************************************************
 * Title : Remove dups Uisng rEcusion.
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
#include <unordered_set>
using namespace std;
void removeDupUtils(ListNode *head) {
  // base case - zero or one node.
  if (!head || !head->next) {
    return;
  }
  // Do head has a subseuennt duplicates -- remove it
  while (head->val == head->next->val) {
    head->next = head->next->next;
    if (!head->next)
      return;
  }
  // Remove result of the duplicates.
  removeDupUtils(head->next);
}
void removeDup(ListNode *head) { removeDupUtils(head); }

int main() {
  ListNode *list = createList({1, 1, 2, 2, 3, 3});
  removeDup(list);
  printList(list); // 1->2->3
  return 0;
}
