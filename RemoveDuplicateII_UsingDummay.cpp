/***************************************************
 * Title : Remove dups using Dummay Nodes
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
#include <unordered_set>
using namespace std;
ListNode *removeDupII(ListNode *head) {
  ListNode *dummy = new ListNode(0);
  dummy->next = head;
  ListNode *pre = dummy;

  while (head != NULL && head->next != NULL) {
    if (head->val == head->next->val) {
      while (head != NULL && head->next != NULL &&
             head->val == head->next->val) {
        head = head->next;
      }
      head = head->next;
      pre->next = head;
    } else {
      pre = pre->next;
      head = head->next;
    }
  }
  return dummy->next; // skip dummay
}

int main() {
  printList(removeDupII(createList({1, 1, 0, 2, 2, 3, 3, 4}))); // 0->4
  return 0;
}
