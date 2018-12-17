/***************************************************
 * Title : Using Heaps
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct compare {
  bool operator()(const ListNode *l, const ListNode *r) {
    return l->val > r->val;
  }
};
ListNode *mergeKLists(vector<ListNode *> lists) {
  priority_queue<ListNode *, vector<ListNode *>, compare> q;
  for (auto l : lists) {
    if (l) {
      q.push(l);
    }
  }
  if (q.empty()) {
    return NULL;
  }

  ListNode *result = q.top();
  q.pop();
  if (result->next) {
    q.push(result->next);
  }
  ListNode *tail = result;
  while (!q.empty()) {
    tail->next = q.top();
    q.pop();
    tail = tail->next;
    if (tail->next) {
      q.push(tail->next);
    }
  }
  return result;
}

int main() {
  printList(mergeKLists(
      {createList({1, 4, 5}), createList({1, 3, 4}), createList({2, 6})}));
  return 0;
}
