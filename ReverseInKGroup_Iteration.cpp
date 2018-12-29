/***************************************************
 * Title : Using Iteration.
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
using namespace std;
// helper function to find if it has k nodes.
bool hasKNodes(ListNode *node, int k) {
  int cnt = 0;
  while (node) {
    cnt++;
    if (cnt >= k)
      return true;
    node = node->next;
  }
  return false;
}
ListNode *reverseKGroup(ListNode *head, int k) {
  if (!hasKNodes(head, k)){
    return head;
  }
  ListNode *new_head = new ListNode(0);
  new_head->next = head;
  ListNode *pre = new_head;
  ListNode *cur = head;
  while (hasKNodes(cur, k)) {
    // perform the reverse.
    for (int i = 0; i < k - 1; i++) {
      ListNode *temp = pre->next;
      pre->next = cur->next;
      cur->next = cur->next->next;
      pre->next->next = temp;
    }
    pre = cur;
    cur = pre->next;
  }
  return new_head->next;
}

int main() {
  printList(reverseKGroup(createList({1, 2, 3, 4, 5}), 2)); // 2->1->4->3->5
  printList(reverseKGroup(createList({1, 2, 3, 4, 5}), 3)); // 3->2->1->4->5
  return 0;
}
