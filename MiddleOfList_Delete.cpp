/***************************************************
 * Title : Delete Node with 3 pointer Apprach
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
using namespace std;
void deleteMiddleNode(ListNode *head) {
  ListNode *slow = head, *fast = head;
  // Use Extra pointer called prev which is is the previous node of slow.
  ListNode *prev;
  while (fast && fast->next) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  prev->next = prev->next->next;
  delete (slow);
}
int main() {
  ListNode *list = createList({1, 2, 3, 4, 5});
  deleteMiddleNode(list);
  printList(list);

  list = createList({1, 2, 3, 4, 5, 6});
  deleteMiddleNode(list);
  printList(list);

  return 0;
}
