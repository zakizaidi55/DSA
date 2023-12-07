#include<iostream>
#include<queue>
using namespace std;


class Node {
    public:
        int data;
        Node* left;
        Node* right;
    
        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* &root, int data) {
    if(root == NULL) {
        
        root = new Node(data);
        // cout << "root ka data " << root->data << endl;
        return root;
    }

    // its not the first node
    if(data > root->data) {
       root->right = insertIntoBST(root->right, data);
    }

    else {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void preorder(Node* root) {
    if(root == NULL)
        return;
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void createBst(Node* &root) {
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cout << "Enter the data : " << endl;
        cin >> data;
    }
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
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
            if(temp->left != NULL ) {
                q.push(temp->left);
            }

            if(temp->right != NULL) {
                q.push(temp->right);
            }   
        }
    }
}

Node* minValue(Node* root) {
    if(root == NULL ) {
        return NULL;
    }

    Node* temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }

    return temp;
}

bool searchInBST(Node* root, int target) {
    // base case
    if(root == NULL)
        return false;
    
    if(root->data == target) 
        return true;
    
    // recursion call
    bool leftAns = false;
    bool rightAns = false;
    if(root->data < target) {
        rightAns = searchInBST(root->right, target);
    }

    else {
        leftAns = searchInBST(root->left, target);
    }

    return leftAns || rightAns;
}

int main() {

    Node* root = NULL;
    createBst(root);

    levelOrderTraversal(root);

    cout <<endl << "printing inorder: "<< endl;
    inorder(root);
    cout << endl << "printing postorder " << endl;
    postorder(root);
    cout << endl << "printing preorder: " << endl;
    preorder(root);

    return 0;
}