#include <iostream>
using namespace std;

class Info () {
  public:
    int maxValue;
    bool isHeap;
    Info(int a, bool b) {
      this->maxValue = a;
      this->isHeap = b;
    }

};

Info checkMaxHeap(Node* root) {
  if(root == NULL) {
    Info temp;
    temp.maxValue = INT_MIN;
    temp.isHeap = true;
    return temp;
  }

  if(root->left == NULL && root->right == NULL) {
    Info temp;
    temp.maxValue = root->data;
    temp.isHeap = true;
    return temp;
  }

  Info leftAns = checkMaxHeap(root->left);
  Info rightAns = checkMaxHeap(root->right);

  // 1 case m solve karunga

  if(root->data > leftAns.maxValue && root->data > rightAns.maxValue && leftAns.isHeap && rightAns.isHeap) {
    Info ans;
    ans.maxValue = root->data;
    ans.isHeap = true;

    return ans;
  }

  else {
    Info ans ;
    ans.maxValue = max(root->data, max(leftAns.maxValue, rightAns.maxValue));
    ans.isHeap = false;
    return ans;
  }
}
int main() {
  cout << "Hello world!" << endl;
  return 0;
}