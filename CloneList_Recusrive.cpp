/***************************************************
 * Title : Recusrive Copy
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
  if (my_map.find(head) != my_map.end()) {
    return my_map[head];
  }
  // not found
  RandomListNode *result = new RandomListNode(head->val);
  my_map.insert(make_pair(head, result));
  result->next = copyRandomList(head->next);
  result->random = copyRandomList(head->random);
  return result;
}

int main() {
  RandomListNode *list =
      createRandomList({0, 1, 2, 3, 4, 5}, {0, 1, 4, 5, 5, 0});
  printRandomList(copyRandomList(list)); // 0(1)->1->2->3->4(5)->5(0)
  return 0;
}
