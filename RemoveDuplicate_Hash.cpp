/***************************************************
 * Title : Remove dups using SET or HASH Map.
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
#include <unordered_set>
using namespace std;
void removeDup(ListNode *start) {
  unordered_set<int> myset;
  if (start == NULL) {
    return;
  }
  ListNode *ptr1 = start;
  myset.insert(start->val);
  while (ptr1 != NULL && ptr1->next != NULL) {
    int val = ptr1->next->val;
    // val exist in the set
    if (myset.find(val) != myset.end()) {
      ListNode *dup = ptr1->next;
      ptr1->next = ptr1->next->next;
      delete (dup);
    } else { // Not exist - please add to the set.
      myset.insert(val);
      ptr1 = ptr1->next;
    }
  }
}

int main() {
  ListNode *list = createList({1, 1, 2, 2, 3, 3});
  removeDup(list);
  printList(list); // 1->2->3
  return 0;
}
