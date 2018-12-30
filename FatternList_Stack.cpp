/***************************************************
 * Title : Using stack;
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
#include <stack>
using namespace std;
DoubleListNode *flatten(DoubleListNode *head) {
  if (head == nullptr) {
    return nullptr;
  }
  // let's create a dummay node to hold the object.
  DoubleListNode *dummy = new DoubleListNode(0);
  DoubleListNode *prev = dummy;
  // create the stack and push the root node.
  stack<DoubleListNode *> st;
  st.push(head);
  // process until stack is empty.
  while (!st.empty()) {
    DoubleListNode *root = st.top();
    root->prev = prev;
    prev->next = root;
    st.pop();
    // Next get low preferences - so push it first.
    if (root->next != nullptr) {
      st.push(root->next);
      root->next = nullptr;
    }
    // Child get the first pref to explore - Push it second.
    if (root->child != nullptr) {
      st.push(root->child);
      root->child = nullptr;
    }
    // We processed the room - means it is now previous.
    prev = root;
  }
  // just discard dummay.
  dummy->next->prev = NULL;
  return dummy->next;
}
int main() {
  DoubleListNode *list = createDoubleList({1, 2, 3, 4, 5, 6});
  list->next->next->child = createDoubleList({7, 8, 9, 10});
  list->next->next->child->next->child = createDoubleList({11, 12});
  printDoubleList(flatten(list)); // 1->2->3->7->8->11->12->9->10->4->5->6
  return 0;
}
