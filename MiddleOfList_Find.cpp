/***************************************************
 * Title : Find Middle of the List
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
using namespace std;
ListNode *middleNode(ListNode *head) {
  ListNode *slow = head, *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}
int main() {
  cout << "Middle:" << middleNode(createList({1, 2, 3, 4, 5}))->val << endl;
  cout << "Middle:" << middleNode(createList({1, 2, 3, 4, 5, 6}))->val << endl;
  return 0;
}
