#include<iostream>
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

int main() {

    Node* root = createTree();
    // levelOrderTraversal(root);

    cout << height(root) << endl;

    return 0;
}