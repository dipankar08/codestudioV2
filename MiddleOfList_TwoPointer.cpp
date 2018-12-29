/***************************************************
 * Title : Delete Node with 2 Pointer
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
using namespace std;
ListNode *deleteMiddleNode(ListNode *head) {
  // one or two nodes.
  if (head == NULL) {
    return NULL;
  }
  if (head->next == NULL) {
    delete head;
    return NULL;
  }
  // We can move the fast pointer by two -so that slow can point to the previous
  // of middle.
  ListNode *slow = head, *fast = head->next->next;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  slow->next = slow->next->next;
  delete (slow);
  return head;
}
int main() {
  printList(deleteMiddleNode(createList({})));
  printList(deleteMiddleNode(createList({1})));
  printList(deleteMiddleNode(createList({1, 2})));
  printList(deleteMiddleNode(createList({1, 2, 3})));
  printList(deleteMiddleNode(createList({1, 2, 3, 4})));
  printList(deleteMiddleNode(createList({1, 2, 3, 4, 5, 6})));
  return 0;
}
