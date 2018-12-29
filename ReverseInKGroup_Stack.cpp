/***************************************************
 * Title : Using Stack
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
#include <stack>
using namespace std;
ListNode *reverseKGroup(ListNode *head, int k) {
  ListNode *curr = head;
  // define resust head and tail as a dumay node.
  ListNode *dummy = new ListNode(0);
  ListNode *tail = dummy;
  // define a stack
  stack<ListNode *> s;
  // process the input list.
  while (curr != nullptr) {
    int ct = 0;
    // push k node inside the stack.
    while (ct < k && curr != nullptr) {
      s.push(curr);
      curr = curr->next;
      ct++;
    }
    // We have less than K node - so keep appending into the tail.
    if (ct < k) {
      ListNode *lastnode = nullptr;
      while (!s.empty()) {
        lastnode = s.top();
        s.pop();
      }
      tail->next = lastnode;
    } else { // we have k node inside the stack so
      while (!s.empty()) {
        tail->next = s.top();
        s.pop();
        tail = tail->next;
      }
      // add the rest of the list that has yet to be reversed back to tail.
      tail->next = curr;
    }
  }
  return dummy->next;
}

int main() {
  printList(reverseKGroup(createList({1, 2, 3, 4, 5}), 2)); // 2->1->4->3->5
  printList(reverseKGroup(createList({1, 2, 3, 4, 5}), 3)); // 3->2->1->4->5
  return 0;
}
