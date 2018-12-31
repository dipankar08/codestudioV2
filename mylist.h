/***************************************************
 * Title : My list Templates
 * Author: Dipankar Dutta
 ****************************************************/
#include <iostream>
#include <vector>
using namespace std;

// single list.
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
template <class T> T *reverse(T *head) {
  T *nhead = NULL;
  while (head) {
    T *next = head->next;
    head->next = nhead;
    nhead = head;
    head = next;
  }
  return nhead;
}
// random list
struct RandomListNode {
  int val;
  RandomListNode *next, *random;
  RandomListNode(int x) : val(x), next(NULL), random(NULL) {}
};
RandomListNode *createRandomList(vector<int> vec,
                                 vector<int> random_assignment) {
  RandomListNode *head = NULL;
  RandomListNode *tail = NULL;
  vector<RandomListNode *> nodes(vec.size());
  for (int i = 0; i < vec.size(); i++) {
    nodes[i] = new RandomListNode(vec[i]);
    if (head == NULL) {
      tail = head = nodes[i];
    } else {
      tail->next = nodes[i];
      tail = tail->next;
    }
  }
  // Now asign the random assignemnet.
  for (int i = 0; i < random_assignment.size(); i += 2) {
    nodes[random_assignment[i]]->random = nodes[random_assignment[i + 1]];
  }
  return head;
}
void printRandomList(RandomListNode *head) {
  while (head != NULL) {
    cout << head->val;
    if (head->random != nullptr) {
      cout << "(" << head->random->val << ")";
    }
    if (head->next != nullptr) {
      cout << "->";
    }
    head = head->next;
  }
  cout << endl;
}

// Double LL with child.
class DoubleListNode {
public:
  int val;
  DoubleListNode *prev;
  DoubleListNode *next;
  DoubleListNode *child;

  DoubleListNode(int _val)
      : val(_val), prev(nullptr), next(nullptr), child(nullptr) {}

  DoubleListNode(int _val, DoubleListNode *_prev, DoubleListNode *_next,
                 DoubleListNode *_child) {
    val = _val;
    prev = _prev;
    next = _next;
    child = _child;
  }
};

DoubleListNode *createDoubleList(vector<int> vec) {
  if (vec.size() == 0) {
    return NULL;
  }
  DoubleListNode *head = NULL;
  DoubleListNode *tail = NULL;
  DoubleListNode *prev = NULL;
  prev = head = tail = new DoubleListNode(vec[0]);
  for (int i = 1; i < vec.size(); i++) {
    tail->next = new DoubleListNode(vec[i]);
    tail = tail->next;
    tail->prev = prev;
    prev = tail;
  }
  return head;
}

void printDoubleList(DoubleListNode *head) {
  while (head != NULL) {
    cout << head->val;
    if (head->child != nullptr) {
      cout << "(" << head->child->val << ")";
    }
    if (head->next != nullptr) {
      cout << "->";
    }
    if (head->prev != nullptr && head->prev->next != head) {
      cout << "List Broken - head->prev->next != head" << endl;
      return;
    }
    head = head->next;
  }
  cout << endl;
}
// TEST :   printList(createList({1,2,3}));