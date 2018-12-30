/***************************************************
 * Title : Tricky Iterative version
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
#include <stack>
using namespace std;
DoubleListNode *flatten(DoubleListNode *head) {
  if (head == nullptr)
    return head;
  // Pointer
  DoubleListNode *p = head;
  while (p != nullptr) {
    /* CASE 1: if no child, proceed */
    if (p->child == nullptr) {
      p = p->next;
      continue;
    }
    /* CASE 2: got child, find the tail of the child and link it to p->next */
    DoubleListNode *temp = p->child;
    // Find the tail of the child
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    // Connect tail with p->next, if it is not nullptr
    temp->next = p->next;
    if (p->next != nullptr) {
      p->next->prev = temp;
    }
    // Connect p with p->child, and remove p->child
    p->next = p->child;
    p->child->prev = p;
    p->child = nullptr;
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
