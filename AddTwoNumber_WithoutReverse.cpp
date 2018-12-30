/***************************************************
 * Title : Adding using forword scan
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
#include <stack>
using namespace std;
ListNode *addToFront(int val, ListNode *head) {
  ListNode *temp = new ListNode(val);
  temp->next = head;
  return temp;
}
// Adding from forword scan.
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  int n1 = 0, n2 = 0, carry = 0;
  ListNode *curr1 = l1, *curr2 = l2, *res = NULL;
  // find the length of both list.
  while (curr1) {
    curr1 = curr1->next;
    n1++;
  }
  while (curr2) {
    curr2 = curr2->next;
    n2++;
  }
  // Use this length info two add it from forword.
  curr1 = l1;
  curr2 = l2;
  while (n1 > 0 && n2 > 0) {
    int sum = 0;
    if (n1 >= n2) {
      sum += curr1->val;
      curr1 = curr1->next;
      n1--;
    }
    if (n2 > n1) {
      sum += curr2->val;
      curr2 = curr2->next;
      n2--;
    }
    res = addToFront(sum, res);
  }
  // handle the carry.
  curr1 = res;
  res = NULL;
  while (curr1) {
    curr1->val += carry;
    carry = curr1->val / 10;
    res = addToFront(curr1->val % 10, res);
    curr2 = curr1;
    curr1 = curr1->next;
    delete curr2;
  }
  // if there is a carry add 1 at front.
  if (carry) {
    res = addToFront(1, res);
  }
  // return.
  return res;
}

int main() {
  printList(addTwoNumbers(createList({7, 2, 4, 3}),
                          createList({5, 6, 4}))); // 7->8->0->7
  return 0;
}
