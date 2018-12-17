/***************************************************
 * Title : Using Merge One By One Using Stack.
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Just a merge Utils
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
  if (l1 == nullptr) {
    return l2;
  }
  if (l2 == nullptr) {
    return l1;
  }
  if (l1->val <= l2->val) {
    l1->next = mergeTwoLists(l1->next, l2);
    return l1;
  } else {
    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
  }
}
// This is using stack - We just take out first two list and merge them and
// insert back. We will keep doing unless we have 1 elemnet left.
ListNode *mergeKLists(vector<ListNode *> lists) {
  if (lists.empty()) {
    return nullptr;
  }
  while (lists.size() > 1) {
    lists.push_back(mergeTwoLists(lists[0], lists[1]));
    lists.erase(lists.begin());
    lists.erase(lists.begin());
  }
  return lists.front();
}

int main() {
  printList(mergeKLists(
      {createList({1, 4, 5}), createList({1, 3, 4}), createList({2, 6})}));
  return 0;
}
