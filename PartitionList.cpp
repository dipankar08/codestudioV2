/***************************************************
 * Title : Partion based on number
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
using namespace std;

ListNode *partition(ListNode *head, int x) {
  // we dedfine two dummy node and
  ListNode *less = new ListNode(0);
  ListNode *more = new ListNode(0);
  // we also define the demand.
  ListNode *less_tail = less;
  ListNode *more_tail = more;
  // just go through the list and then partion it into two part.
  while (head != nullptr) {
    if (head->val < x) {
      less_tail->next = head;
      less_tail = less_tail->next;
    } else {
      more_tail->next = head;
      more_tail = more_tail->next;
    }
    head = head->next;
  }
  // set the nullptr to avoid the loop.
  more_tail->next = nullptr; // this is needed to avoid cycle.
  less_tail->next = nullptr;
  // printList(less);
  // printList(more);
  // merge two list
  less_tail->next = more->next;
  // return head of less.
  return less->next;
}

int main() {
  printList(partition(createList({1, 4, 3, 2, 5, 2}), 3));
  printList(partition(createList({5}), 3));
  return 0;
}
