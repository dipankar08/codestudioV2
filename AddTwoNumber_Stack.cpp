/***************************************************
 * Title : Solving using stack
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
#include <stack>
using namespace std;
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  // we have two stack and put the nodes of the list in reverse order
  stack<int> s1;
  stack<int> s2;
  while (l1 != nullptr) {
    s1.push(l1->val);
    l1 = l1->next;
  };
  while (l2 != nullptr) {
    s2.push(l2->val);
    l2 = l2->next;
  }

  int sum = 0;
  // create dummay nodes. 
  ListNode *list = new ListNode(0);
  while (!s1.empty() || !s2.empty()) {
    if (!s1.empty()) {
      sum += s1.top();
      s1.pop();
    }
    if (!s2.empty()) {
      sum += s2.top();
      s2.pop();
    }
    // create a node and append to the result.
    list->val = sum % 10;
    ListNode *head = new ListNode(sum / 10);
    head->next = list;
    list = head;
    sum /= 10;
  }
  return list->val == 0 ? list->next : list;
}
int main() {
  printList(addTwoNumbers(createList({7, 2, 4, 3}),
                          createList({5, 6, 4}))); // 7->8->0->7
  return 0;
}
