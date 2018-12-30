/***************************************************
 * Title : Recustion with static veriable
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
using namespace std;

void populateGreater(RandomListNode *head) {
  if (head == nullptr) {
    return;
  }
  // we define this static veriable.
  static RandomListNode *maxNode;
  // at the base case we initilize this as a last node.
  if (head->next == nullptr) {
    maxNode = head;
    return;
  }
  // recusrive.
  populateGreater(head->next);
  // Once we are coming back update the random pointer.
  head->random = maxNode;
  // now, calculate it for the next one to be used.
  if (head->val > maxNode->val) {
    maxNode = head;
  }
}

int main() {
  RandomListNode *list = createRandomList({5, 10, 2, 3}, {});
  populateGreater(list);
  printRandomList(list); // 5(10)->10(3)->2(3)->3.
  return 0;
}
