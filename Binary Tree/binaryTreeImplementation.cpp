#include<iostream>


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
    cout << "left of node  " << root->data << endl; 
    root->left = createTree();

    // create right subtree
    cout << "right of the node " << root->data << endl;
    root->right = createTree();

    return root;
}  

int main() {

    Node* root = createTree();

    return 0;
}