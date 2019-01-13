/***************************************************
 * Title : Tree related DS
 * Author: Dipankar Dutta
 ****************************************************/
#include <iostream>
#include <queue>
#include<vector>
using namespace std;
#define tnull 1000
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printTreeHelper(TreeNode *root) {
  if (root == NULL) {
    return;
  }
  cout << root->val << " ";
  printTreeHelper(root->left);
  printTreeHelper(root->right);
}


TreeNode *createTree(vector<int> data) {
  if (data.size() == 0) {
    return nullptr;
  }
  queue<TreeNode *> q;
  int index = 0;
  TreeNode *root = new TreeNode(data[index++]);
  q.push(root);
  while(!q.empty() && index <data.size()){
    TreeNode * now_temp = q.front();
    q.pop();
    if(data[index] != tnull){
      TreeNode * temp = new TreeNode(data[index++]);
      q.push(temp);
      now_temp->left = temp;
    } else{
      index++;
    }
    if(index<data.size()){
      if(data[index] != tnull){
      TreeNode * temp = new TreeNode(data[index++]);
      q.push(temp);
      now_temp->right = temp;
      } else{
        index++;
      }
    }
  }
  return root;
}

void printTree(TreeNode *root) {
  cout << "Tree(pre-order):" << endl;
  printTreeHelper(root);
  cout << endl;
}

/***
    1
   / \
  2   3
     / \
    4   5

as printTree(createTree({1,2,3,tnull,tnull,4,5}))

[] => empty
[1,2,3] =>  1 is root and 2 left and 3 is right.

see others : https://support.leetcode.com/hc/en-us/articles/360011883654-What-does-1-null-2-3-mean-in-binary-tree-representation-
****/