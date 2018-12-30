/***************************************************
 * Title : Iterative Solution 
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<RandomListNode *, RandomListNode *> my_map;

RandomListNode *copyRandomList(RandomListNode *head) {
  if (head == nullptr) {
    return nullptr;
  }
  RandomListNode *ansHead, *ansTail;
  // Just create a copy of the orilist as per the linier list and store the
  // mapping.
  RandomListNode *cur = head;
  for (cur = head; cur != nullptr; cur = cur->next) {
    RandomListNode *temp = new RandomListNode(cur->val);
    if (ansHead == nullptr) {
      ansHead = ansTail = temp;
    } else {
      ansTail->next = temp;
      ansTail = ansTail->next;
    }
    my_map.insert(make_pair(cur, temp));
  }

  // Do another iteration for assignment of random.
  for (cur = head; cur != nullptr; cur = cur->next) {
    my_map[cur]->random = my_map[cur->random];
  }
  return ansHead;
}

int main() {
  RandomListNode *list =
      createRandomList({0, 1, 2, 3, 4, 5}, {0, 1, 4, 5, 5, 0});
  printRandomList(copyRandomList(list)); // 0(1)->1->2->3->4(5)->5(0)
  return 0;
}
