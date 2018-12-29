/***************************************************
 * Title : Delete Node Using recustion.
 * Author: Dipankar Dutta
 ****************************************************/
#include "mylist.h"
#include <iostream>
using namespace std;
// in this recustion, the length wil be calculated while going to the recustion
// stack and post wil be calculated while poping back from the stack.
void recursion(ListNode *node, int &length, int &post) {
  if (node == nullptr) {
    return;
  }
  // before recusrion.
  length++;
  recursion(node->next, length, post);
  // after recusrion.
  post++;
  // cout << "node:" << node->val << " Length:" << length << " Post" << post<<
  // endl;

  // This condidtion is little tricky - print the privous debug statemnet to
  // undetatnd the co-relation.
  if (length % 2 == 0) {
    if (length / 2 + 1 == post) {
      node->next = node->next->next;
    }
  } else {
    if (length / 2 + 2 == post) {
      node->next = node->next->next;
    }
  }
}

ListNode *deleteMiddleNode(ListNode *head) {
  // one or two nodes.
  if (head == NULL) {
    return NULL;
  }
  if (head->next == NULL) {
    delete head;
    return NULL;
  }
  int length = 0;
  int post = 0;
  recursion(head, length, post);
  return head;
}
int main() {
  printList(deleteMiddleNode(createList({})));                 //{}
  printList(deleteMiddleNode(createList({1})));                // {}
  printList(deleteMiddleNode(createList({1, 2})));             // 1
  printList(deleteMiddleNode(createList({1, 2, 3})));          // 1->3
  printList(deleteMiddleNode(createList({1, 2, 3, 4})));       // 1->2->4
  printList(deleteMiddleNode(createList({1, 2, 3, 4, 5, 6}))); // 1->2->3->5-6
  return 0;
}
