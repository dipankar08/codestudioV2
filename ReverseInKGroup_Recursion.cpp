/***************************************************
 * Title : Using recursion
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
using namespace std;

// helper function to revser a list <first .. last>
ListNode *reverse(ListNode *first, ListNode *last) {
  ListNode *prev = last;
  while (first != last) {
    auto tmp = first->next;
    first->next = prev;
    prev = first;
    first = tmp;
  }
  return prev;
}

ListNode *reverseKGroup(ListNode *head, int k) {
  auto node = head;
  // Let;s find the k+1th node.
  for (int i = 0; i < k; ++i) {
    if (!node) {
      return head; // nothing to do list too sort
    }
    node = node->next;
  }
  // reverse the list from head.. node -1, head would be the new tail.
  auto new_head = reverse(head, node);
  head->next = reverseKGroup(node, k);
  return new_head;
}

int main() {
  printList(reverseKGroup(createList({1, 2, 3, 4, 5}), 2)); // 2->1->4->3->5
  printList(reverseKGroup(createList({1, 2, 3, 4, 5}), 3)); // 3->2->1->4->5
  return 0;
}
