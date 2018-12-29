/***************************************************
 * Title : Remove dups Without Dummay Nodes
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
#include <unordered_set>
using namespace std;
ListNode *removeDupII(ListNode *head) {
  ListNode *p = head, *tail = NULL;
  // We will scan over the full list from left to right.
  while (p != NULL) {
    ListNode *q = p->next;
    // detect if p is a duplicate and will keep all possible duplicates
    // which is ahead of p.
    if (q && q->val == p->val) {
      while (q && q->val == p->val) {
        q = q->next;
      }
    } else {
      // ok there is no duplicate for p - so we can add p in the result
      if (tail) {
        tail->next = p;
      } else {
        head = p;
      }
      tail = p;
    }
    p = q;
  }
  // note that the output might be empty.
  if (tail == NULL) {
    return NULL;
  } else {
    tail->next = NULL;
    return head;
  }
}

int main() {
  printList(removeDupII(createList({1, 1, 0, 2, 2, 3, 3, 4}))); // 0->4
  return 0;
}
