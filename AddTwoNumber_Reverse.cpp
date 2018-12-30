/***************************************************
 * Title : Solving using stack
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
#include <stack>
using namespace std;
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *n1 = reverse(l1);
  ListNode *n2 = reverse(l2);
  int carry = 0;
  ListNode *ansHead = n1;
  ListNode *anstail = n1;
  while (n1 != nullptr || n2 != nullptr || carry != 0) {
    int v1 = (n1 == nullptr) ? 0 : n1->val;
    int v2 = (n2 == nullptr) ? 0 : n2->val;
    if (n1 == nullptr) {
      n1 = new ListNode((v1 + v2 + carry) % 10);
      anstail->next = n1;
    } else {
      n1->val = (v1 + v2 + carry) % 10;
    }
    carry = (v1 + v2 + carry) / 10;
    anstail = n1;
    n1 = (n1 == nullptr) ? nullptr : n1->next;
    n2 = (n2 == nullptr) ? nullptr : n2->next;
  }
  return reverse(ansHead);
}

int main() {
  printList(addTwoNumbers(createList({7, 2, 4, 3}),
                          createList({5, 6, 4}))); // 7->8->0->7
  return 0;
}
