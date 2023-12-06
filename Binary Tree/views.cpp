#include <iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;



class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
      this->data = data;
      left = NULL;
      right = NULL; 
    }


};


Node* createTree() {
  int value;
  cout << "Enter the value for NOde " << endl;
  cin >> value;

  if(value == -1) {
    return NULL;
  }

  // create the node
  Node* root = new Node(value);

  cout << "enterign the value of left " << value << endl;

  root->left = createTree();
  cout << "enterign the value of right " << value << endl;
  root->right = createTree();

  return root;
}


void preorder (Node*root) {
  if(root == NULL) {
    return;
  }

  cout << root->data << endl;

  preorder(root->left);
  preorder(root->right);

}
void inorder (Node*root) {
  if(root == NULL) {
    return;
  }

  inorder(root->left);
  cout << root->data << endl;
  inorder(root->right);

}

void postorder(Node*root) {
  if(root == NULL) {
    return;
  }

  postorder(root->left);
  postorder(root->right);
  cout << root->data << endl;

}


void levelorder(Node* root) {
  queue<Node*> q;
  q.push(root);
  q.push(NULL);
  cout << endl;
  while(!q.empty()) {
    Node* temp = q.front();
    q.pop();

    if(temp == NULL) {
      cout << endl;
      if(!q.empty()) {
        q.push(NULL);
      }
    }

    else {
      cout << temp->data << " ";

      if(temp->left) {
        q.push(temp->left);
      }
      if(temp->right) {
        q.push(temp->right);
      }
    }
  }
}


void printLeftView(Node* root, int level, vector<int>& leftView) {
  if(root == NULL) {
    return;
  }

  if(level == leftView.size()) {
    leftView.push_back(root->data);
  }

  printLeftView(root->left, level+1, leftView);
  printLeftView(root->right, level+1, leftView);

}

void printRightView(Node* root, int level, vector<int>& rightView) {
  if(root == NULL) {
    return;
  }

  if(level == rightView.size()) {
    rightView.push_back(root->data);
  }

  printLeftView(root->right, level+1, rightView);
  printLeftView(root->left, level+1, rightView);
  

}

void printTopView(Node* root) {
  map<int,int> hdToNode;
  queue<pair<Node*, int> >q;
  q.push(make_pair(root, 0));

  while(!q.empty()) {
    pair<Node*, int> temp = q.front();
    q.pop();

    Node* frontNode = temp.first;
    int hd = temp.second;  //horizontal distance

    // if there is no answer fot this horizontal distance , then this comes very first time 
    // store it

    // if there is no entry in the map, store it
    if(hdToNode.find(hd) == hdToNode.end()) {
      hdToNode[hd] = frontNode->data;
    }

    if(frontNode->left != NULL) {
      q.push(make_pair(frontNode->left, hd-1));
    }

    if(frontNode->right != NULL) {
      q.push(make_pair(frontNode->right, hd+1));
    }
  }

  cout <<"Printing top View " << endl;
  for(auto i : hdToNode) {
    cout << i.second << " " ;
  }

}

void printBottomView(Node* root) {
  map<int,int> hdToNode;
  queue<pair<Node*, int> >q;
  q.push(make_pair(root, 0));

  while(!q.empty()) {
    pair<Node*, int> temp = q.front();
    q.pop();

    Node* frontNode = temp.first;
    int hd = temp.second;  //horizontal distance

    // if there is no answer fot this horizontal distance , then this comes very first time 
    // store it

    // if there is no entry in the map, store it
    
     hdToNode[hd] = frontNode->data;
    

    if(frontNode->left != NULL) {
      q.push(make_pair(frontNode->left, hd-1));
    }

    if(frontNode->right != NULL) {
      q.push(make_pair(frontNode->right, hd+1));
    }
  }

  cout <<"Printing top View " << endl;
  for(auto i : hdToNode) {
    cout << i.second << " " ;
  }

}

int main() {
  Node* root = createTree();
  // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
  // cout << root << endl;
  // levelorder(root);
  vector<int>leftView;
  // printLeftView(root, 0, leftView);
  
  printTopView(root);

  // for(auto i: leftView) {
  //   cout << i << " ";
  // }
  return 0;
}