/***************************************************
 * Title : Two Scan approach.
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
using namespace std;
void deleteMiddleNode(ListNode *head) {
  // Iterate thouygh the list and find the number of element;
  int count = 0;
  ListNode *temp = head;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  // Again scan the elment and find the prev node of middle and delete the
  // middle.
  temp = head;
  for (int i = 0; i < count / 2 - 1; i++) {
    temp = temp->next;
  }
  ListNode *dup = temp->next;
  temp->next = temp->next->next;
  delete (dup);
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
