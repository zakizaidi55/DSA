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

Node* maxValue(Node* root) {
    if(root == NULL ) {
        return NULL;
    }

    Node* temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
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

Node* deleteFromBST(Node* root, int target) {
    // cout << "inside the delete call " << endl;
    // cout <<" target " << target << endl;
    // target ko find and delete
    if(root == NULL) {
        return NULL;
    }

    if(root->data == target ) {
        if(root->left == NULL && root->right == NULL) {
            return NULL;
        }

        else if(root->left != NULL && root->right == NULL) {
            Node* childSubTree = root->left;
            delete root;
            return childSubTree;
        }

        else if(root->left == NULL && root->right != NULL) {
            Node* chidlSubTree = root->right;
            delete root;
            return chidlSubTree;
        }

        else {
            // step1 find the max value from left subtree
            Node* maxi =  maxValue(root->left);
            // replacement
            root->data = maxi->data;

            // delete actual maxi node
            root->left = deleteFromBST(root->left, maxi->data);
            return root;
        }
    }

    else if(root->data > target) {
        root->left = deleteFromBST(root->left, target);
    }

    else {
        root->right = deleteFromBST(root->right, target);
    }

    return root;
}


Node* bstFromInorder(int inorder[], int size, int start, int end) {
    if(start > end) {
        return NULL;
    }

    int mid = (start + end)/2;
    int element = inorder[mid];

    Node* root = new Node(element);

    root->left = bstFromInorder(inorder, size, start, mid-1 );

    root->right = bstFromInorder(inorder, size, mid+1, end);

    return root;

}


// convert this BST into sorted Doubly linked list
void convertBSTtoDLL(Node* root, Node* &head) {
    if(root == NULL) {
        return;

    }

    // RNL
    // R
    convertBSTtoDLL(root->right, head);

    // N
    root->right = head;
    if(head != NULL) 
        head->left = root;

    head = root;

    // l
    convertBSTtoDLL(root->left, head);
}

Node* convertDLLToBST(Node* &head, int n) {
    if (head == NULL || n <= 0)
        return NULL;
    

    // LNR
    Node* leftSubTree = convertDLLToBST(head, n/2);

    // N
    Node* root = head;
    root->left = leftSubTree;
    head = head->right;

    //R
    Node* rightSubTree = convertDLLToBST(head, n-n/2-1);
    root->right = rightSubTree;

    return root;



}

void printLL(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }
}

int main() {

    // Node* root = NULL;
    createBst(root);

    // levelOrderTraversal(root);

    // cout <<endl << "printing inorder: "<< endl;
    // inorder(root);
    // cout << endl << "printing postorder " << endl;
    // postorder(root);
    // cout << endl << "printing preorder: " << endl;
    // preorder(root);
    // int target = 20;
    // deleteFromBST(root, target);
    // cout << "after Delete " << endl;
    // levelOrderTraversal(root);

    int inorder[] = {10,20,30,40,50,60};
    int size = 6;

    int start = 0;
    int end = size-1;

    Node* root = bstFromInorder(inorder, size, start, end);

    levelOrderTraversal(root);
    // Node* head = NULL;
    // convertBSTtoDLL(root, head);
    // convertDLLToBST(Node* head, int n);
    // cout << "Printing the linked list " << endl;
    // printLL(head); 
    return 0;
}