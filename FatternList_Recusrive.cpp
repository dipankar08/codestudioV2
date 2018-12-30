/***************************************************
 * Title : Tricky Iterative version
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
#include <stack>
using namespace std;
// global verable tracks as previous
DoubleListNode *prevv;
DoubleListNode *flatten(DoubleListNode *head) {
  DoubleListNode *cur = head;
  while (cur != nullptr) {
    // have a child
    if (cur->child != nullptr) {
      // We need to do the recusrion call for the child. But make sure you do:
      // 1) we need to set the prev of child.
      // 2) set the child as nullptr to avoid loop.
      // 3) set the next to return of recusrion.
      // 4) if next is not null, update the prev and next.
      DoubleListNode *next = cur->next;
      cur->child->prev = cur;
      cur->next = flatten(cur->child);
      cur->child = nullptr;
      if (next != nullptr) {
        prevv->next = next;
        next->prev = prevv;
      }
    } else { // no child pointer - just update prev and forword cur.
      prevv = cur;
      cur = cur->next;
    }
  }
  return head;
}
int main() {
  DoubleListNode *list = createDoubleList({1, 2, 3, 4, 5, 6});
  list->next->next->child = createDoubleList({7, 8, 9, 10});
  list->next->next->child->next->child = createDoubleList({11, 12});
  printDoubleList(flatten(list)); // 1->2->3->7->8->11->12->9->10->4->5->6
  return 0;
}
