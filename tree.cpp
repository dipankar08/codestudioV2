/***************************************************
 * Title : Function to print the tree
 * Author: Dipankar Dutta
 ****************************************************/
#include "tree.h"
#include <iostream>
#include <stack>
using namespace std;

// INORDER
void inorder(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

// PRE ORDER
void preorder(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  cout << root->val << " ";
  preorder(root->left);
  preorder(root->right);
}

// POST ORDER
void postorder(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout << root->val << " ";
}

// ITERATIVE INORDER
void iinorder(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  stack<TreeNode *> s;
  TreeNode *curr = root;
  while (curr != nullptr || !s.empty()) {
    // keep push all it's left node
    while (curr != nullptr) {
      s.push(curr);
      curr = curr->left;
    }
    // No more left - so print it.
    curr = s.top();
    s.pop();
    cout << curr->val << " ";
    // Try for right child.
    curr = curr->right;
  }
}

// ITERATIVE PRE _ORDER
void ipreorder(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  stack<TreeNode *> s;
  s.push(root);
  while (!s.empty()) {
    // as it is pre, we just take the root
    TreeNode *temp = s.top();
    s.pop();
    cout << temp->val << " ";
    // we push right first and then left so that while pop, we get the left
    // first and then right.
    if (temp->right != nullptr) {
      s.push(temp->right);
    }
    if (temp->left != nullptr) {
      s.push(temp->left);
    }
  }
}

// ITERATIVE POST ODDER
void ipostorder(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  // here, we take a stack, the stack might conatins the node for just for
  // priting or for processing: true means processing.
  stack<pair<bool, TreeNode *>> stk;
  stk.push({true, root});
  while (!stk.empty()) {
    auto &p = stk.top();
    if (p.first) { // We need to process this , just chnage the flag but not
                   // pop.
      p.first = false;
      // Note that we push right first and then push left
      if (p.second->right) {
        stk.push({true, p.second->right});
      }
      if (p.second->left) {
        stk.push({true, p.second->left});
      }
    } else { // We just needs for priting.
      cout << p.second->val << " ";
      stk.pop();
    }
  }
}

// LEVEL ORDER
void levelOrder(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode *temp = q.front();
    q.pop();
    cout << temp->val << " ";
    if (temp->left != nullptr) {
      q.push(temp->left);
    }
    if (temp->right != nullptr) {
      q.push(temp->right);
    }
  }
}

// LEVEL ORDER
void levelOrderWithoutMarker(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    // we tarck the current size ( indicate they are on same level)
    int size = q.size();
    for (int i = 0; i < size; i++) {
      TreeNode *temp = q.front();
      q.pop();
      cout << temp->val << " ";
      if (temp->left != nullptr) {
        q.push(temp->left);
      }
      if (temp->right != nullptr) {
        q.push(temp->right);
      }
    }
    cout << endl;
  }
}

// Level Order using two queue
void levelOrderUsingtwoQueue(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  queue<TreeNode *> q1, q2;
  q1.push(root);
  while (!q1.empty() || !q2.empty()) {
    cout << endl;
    while (!q1.empty()) {
      TreeNode *temp = q1.front();
      q1.pop();
      cout << temp->val << " ";
      if (temp->left != nullptr) {
        q2.push(temp->left);
      }
      if (temp->right != nullptr) {
        q2.push(temp->right);
      }
    }
    cout << endl;
    while (!q2.empty()) {
      TreeNode *temp = q2.front();
      q2.pop();
      cout << temp->val << " ";
      if (temp->left != nullptr) {
        q1.push(temp->left);
      }
      if (temp->right != nullptr) {
        q1.push(temp->right);
      }
    }
  }
}

int main() {
  TreeNode *root = createTree({1, 2, 3, 4, 5, tnull, 6, tnull, 7, tnull, 8});
  cout << "\nPre-order:" << endl;
  preorder(root);
  cout << "\nPre-order:" << endl;
  ipreorder(root);
  cout << "\nIn-order:" << endl;
  inorder(root);
  cout << "\nIn-order:" << endl;
  iinorder(root);
  cout << "\nPost-Order:" << endl;
  postorder(root);
  cout << "\nPost-Order:" << endl;
  ipostorder(root);
  cout << "\nLevel-Order:" << endl;
  levelOrder(root);
  cout << "\nlevelOrderWithoutMarker:" << endl;
  levelOrderWithoutMarker(root);
  cout << "\nlevelOrderWithoutMarker:" << endl;
  levelOrderUsingtwoQueue(root);
  cout << endl;
  return 0;
}
