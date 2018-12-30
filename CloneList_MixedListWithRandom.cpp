/***************************************************
 * Title : Alternative solution with extra space.
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
using namespace std;

RandomListNode *copyRandomList(RandomListNode *head) {
  RandomListNode *newHead, *l1, *l2;
  if (head == NULL) {
    return NULL;
  }
  // Here we point the duplicate nodes by the random pointer and duplicate nodes
  // points the random node. 1(3)->2-3  will convert to 1->2-3 where Random of 1
  // is 1->1(c)->3
  for (l1 = head; l1 != NULL; l1 = l1->next) {
    l2 = new RandomListNode(l1->val);
    l2->next = l1->random;
    l1->random = l2;
  }
  // So new head is the head's random.
  newHead = head->random;
  // assign the next elemnet propely.
  for (l1 = head; l1 != NULL; l1 = l1->next) {
    l2 = l1->random;
    l2->random = l2->next ? l2->next->random : NULL;
  }
  // breaked the mixed list.
  for (l1 = head; l1 != NULL; l1 = l1->next) {
    l2 = l1->random;
    l1->random = l2->next;
    l2->next = l1->next ? l1->next->random : NULL;
  }
  return newHead;
}

int main() {
  RandomListNode *list =
      createRandomList({0, 1, 2, 3, 4, 5}, {0, 1, 4, 5, 5, 0});
  printRandomList(copyRandomList(list)); // 0(1)->1->2->3->4(5)->5(0)
  return 0;
}
