/***************************************************
 * Title : Two Loop approach.
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
using namespace std;

void populateGreater(RandomListNode *node) {
  while (node->next != nullptr) {
    RandomListNode *maxNode = node->next;
    RandomListNode *cur = maxNode;
    while (cur != nullptr) {
      if (cur->val > maxNode->val) {
        maxNode = cur;
      }
      cur = cur->next;
    }
    node->random = maxNode;
    node = node->next;
  }
}

int main() {
  RandomListNode *list = createRandomList({5, 10, 2, 3}, {});
  populateGreater(list);
  printRandomList(list); // 5(10)->10(3)->2(3)->3.
  return 0;
}
