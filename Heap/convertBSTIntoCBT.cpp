#include <iostream>
#include<vector>
using namespace std;

void storeInorderTraversal(Node* root, vector<int>& v) {
  if(root == NULL) 
    return;
  
  storeInorderTraversal(root->left);
  v.push(root->val);
  storeInorderTraversal(root->right);
}

Node* convertBSTIntoMaxHeap(Node* root) {
  vector<int> v;
  storeInorderTraversal(root, v);

  // replace the nodes value 
  int index = 0;
  replaceUsingPostOrder(root, v, index);

  return root;
}

void replaceUsingPostOrder(Node* root, vector<int>&v, int& index) {
  if(root == NULL)
    return;

  replaceUsingPostOrder(root->left, v);
  replaceUsingPostOrder(root->right, v);
  root->data = v[index];
  index++;
}

int main() {
  cout << "Hello world!" << endl;
  return 0;
}