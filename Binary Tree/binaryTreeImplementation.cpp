#include<iostream>
#include<map>
#include<queue>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }        

};

Node* createTree() {
    cout << "Enter the data " << endl;
    int data; 
    cin >> data;

    if(data == -1) {
        return NULL;
    }

    Node* root = new Node(data);
    // create left subtree
    // cout << "left of node  " << root->data << endl; 
    root->left = createTree();

    // create right subtree
    // cout << "right of the node " << root->data << endl;
    root->right = createTree();

    return root;
}  

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    // initially
    q.push(root);
    q.push(NULL);
    

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
            cout << temp->data << " " ;
            if(temp->left) {
                q.push(temp->left);
            }

            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void inorderTraversal(Node* root) {
    // base case
    if(root == NULL) {
        return;
    }

    // left part
    inorderTraversal(root->left);

    // printing
    cout << root->data << " ";

    // right part
    inorderTraversal(root->right);
}


void preorderTraversal(Node* root) {
    // base case
    if(root == NULL) {
        return;
    }

    // printing
    cout << root->data << " ";

    // left part
    inorderTraversal(root->left);

  

    // right part
    inorderTraversal(root->right);
}


void postorderTraversal(Node* root) {
    // base case
    if(root == NULL) {
        return;
    }
    
    // left part
    inorderTraversal(root->left);

    // right part
    inorderTraversal(root->right);

    // printing
    cout << root->data << " ";
}

int height(Node* root) {
    if(root == NULL) {
        return 0;
    }

    // left height
    int leftHeight = height(root->left);

    // right height
    int rightHeight = height(root->right);


    int ans = max(leftHeight, rightHeight) + 1;


    return ans;
}

int searchInorder(int inorder[],int size, int element) {
    for(int i=0; i<size; i++) {
        if(inorder[i] == element)
            return i;
    }

    return -1;
}

void createMapping(int inorder[],int size, map<int, int> &valueToIndexMap) {
    for(int i=0; i<size; i++) {
        int element = inorder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

// sabse important path h preorder ko by ref pass karna padega
Node* constructTreeFromInorderAndPreorder(int preorder[], int inorder[],int& preIndex, int inorderStart, map<int, int>&valueToIndexMap, int inorderEnd, int size ){
    // base case
    if(preIndex >= size || inorderStart > inorderEnd) {
        return NULL;
    }

    // 1 case solve
    int element = preorder[preIndex];
    preIndex++;

    Node* root = new Node(element);

    // element->search in order
    // int position = searchInorder(inorder,size, element);

    int position = valueToIndexMap[element];

    root->left = constructTreeFromInorderAndPreorder(preorder, inorder, preIndex, inorderStart, valueToIndexMap, position-1, size);
    root->right = constructTreeFromInorderAndPreorder(preorder, inorder, preIndex, position+1, valueToIndexMap, inorderEnd, size);


    return root;    

}

int main() {

    // Node* root = createTree();
    // levelOrderTraversal(root);

    // cout << height(root) << endl;

    int inorder[] = {10,8,6,2,4,12};
    int preorder[] = {2,8,10,6,4,12};

    int size = 6;
    int preorderIndex = 0;
    int inorderStart = 0;
    int inorderEnd = 5;
    map<int, int> valueToIndexMap;
    createMapping(inorder, size, valueToIndexMap);
    Node* root = constructTreeFromInorderAndPreorder(preorder, inorder, preorderIndex, inorderStart,valueToIndexMap, inorderEnd, size);

    cout <<"printing entire tree" << endl;
    levelOrderTraversal(root);
    return 0;
}