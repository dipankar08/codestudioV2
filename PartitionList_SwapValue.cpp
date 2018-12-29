/***************************************************
 * Title : Swap with Recustion.
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
using namespace std;

ListNode *partition(ListNode *head, int x) {
  if (!head) {
    return NULL;
  }
  // call the recustion for next to head
  head->next = partition(head->next, x);
  ListNode *node = head;
  // If the current node is higher, then it should be replaced by the smaler
  // value. So we wikk find the next less and make the swap.
  if (node->val >= x) {
    while (node->next && node->next->val < x) {
      swap(node->val, node->next->val);
      node = node->next;
    }
  }
  return head;
}
int main() {
  printList(partition(createList({1, 4, 3, 2, 5, 2}), 3));
  printList(partition(createList({5}), 3));
  return 0;
}
