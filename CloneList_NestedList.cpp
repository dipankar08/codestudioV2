/***************************************************
 * Title : By building Nested List
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
using namespace std;

RandomListNode *copyRandomList(RandomListNode *head) {
  // Consider l1 as a node on the 1st list and l2 as the corresponding node on
  // 2nd list.
  RandomListNode *newHead, *l1, *l2;
  if (head == NULL) {
    return NULL;
  }
  // We are creating a new list in such a way : 1->2->3 to
  // 1->1(copiped)->2->2(copied)->3->3(copied)
  for (l1 = head; l1 != NULL; l1 = l1->next->next) {
    l2 = new RandomListNode(l1->val);
    l2->next = l1->next;
    l1->next = l2;
  }
  // printRandomList(head);

  // Scan agin the list and if the node has a random pointer, we should also set
  // the  random pointer to next.
  newHead = head->next;
  for (l1 = head; l1 != NULL; l1 = l1->next->next) {
    if (l1->random != NULL) {
      l1->next->random = l1->random->next;
    }
  }

  // Now break this nested list into two list.
  for (l1 = head; l1 != NULL; l1 = l1->next) {
    l2 = l1->next;
    l1->next = l2->next;
    if (l2->next != NULL) {
      l2->next = l2->next->next;
    }
  }
  // return the new head
  return newHead;
}

int main() {
  RandomListNode *list =
      createRandomList({0, 1, 2, 3, 4, 5}, {0, 1, 4, 5, 5, 0});
  printRandomList(copyRandomList(list)); // 0(1)->1->2->3->4(5)->5(0)
  return 0;
}