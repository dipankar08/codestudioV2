/***************************************************
 * Title : My list Templates
 * Author: Dipankar Dutta
 ****************************************************/
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
ListNode *createList(vector<int> vec) {
  ListNode *head = NULL;
  ListNode *tail = NULL;
  for (int i : vec) {
    if (head == NULL) {
      tail = head = new ListNode(i);
    } else {
      tail->next = new ListNode(i);
      tail = tail->next;
    }
  }
  return head;
}
void printList(ListNode *head) {
  while (head != NULL) {
    cout << head->val << (head->next == NULL ? "" : "->");
    head = head->next;
  }
  cout << endl;
}

// TEST :   printList(createList({1,2,3}));