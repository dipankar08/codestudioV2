/***************************************************
 * Title : Two Loop approach.
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
using namespace std;

void populateGreater(RandomListNode *head) {
  head = reverse(head);
  RandomListNode *maxNode = head;
  RandomListNode *cur = head->next;
  while (cur != nullptr) {
    cur->random = maxNode;
    if (cur->val > maxNode->val) {
      maxNode = cur;
    }
    cur = cur->next;
  }
  reverse(head);
}

int main() {
  RandomListNode *list = createRandomList({5, 10, 2, 3}, {});
  populateGreater(list);
  printRandomList(list); // 5(10)->10(3)->2(3)->3.
  return 0;
}
