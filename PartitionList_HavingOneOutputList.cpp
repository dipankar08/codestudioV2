/***************************************************
 * Title : Prepend and Append
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
using namespace std;

ListNode *partition(ListNode *head, int x) {
  if (!head) {
    return NULL;
  }
  // Assume we have a single output list - which has a head and tail and
  // as we process the list, we either append or prepend the node to this.
  ListNode *ansHead, *ansTail;
  ansHead = ansTail = head;
  head = head->next;
  while (head != nullptr) {
    // save the next as temp as head->next will be destroyed.
    ListNode *temp = head->next;
    head->next = nullptr;
    // if value is less - just prepend to the ans list.
    if (head->val < x) {
      // this is the first node aso update the tail.
      if (ansTail == nullptr) {
        ansTail = ansHead = head;
      } else {
        head->next = ansHead;
        ansHead = head;
      }
    } else {
      // first node
      if (ansTail == nullptr) {
        ansHead = ansTail = head;
      } else {
        ansTail->next = head;
        ansTail = ansTail->next;
      }
    }
    head = temp;
  }
  return ansHead;
}
int main() {
  printList(partition(createList({1, 4, 3, 2, 5, 2}), 3));
  printList(partition(createList({5}), 3));
  return 0;
}
