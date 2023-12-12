#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
        int data;
        int childCount;
        Node** children;

        Node(int value) {
            this->data = value;
            this->childCount = 0;
            this->children = 0;
        }
};


Node* takeInput() {
    int data;
    int count;
    cout << "enter root data " << endl;
    cin >> data;
    cout << "Enter the children count for " << data << endl;
    cin >> count;

    Node* root = new Node(data);
    root->childCount = count;
    root->children = new Node*[count]; //array to store the link of childremn

    for(int i=0; i<count; i++) {
        root->children[i] = takeInput();
    }

    return root;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        if(front == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }

        else {
            cout << front->data << " ";

            for(int i=0; i<front->childCount; i++) {
                if(front->children[i]) {
                    q.push(front->children[i]);
                }
            }
        }
    }
}

int main() {
    Node* root = takeInput();
    levelOrderTraversal(root);
}