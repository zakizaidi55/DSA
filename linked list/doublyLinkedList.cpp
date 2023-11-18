#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;


    Node() {
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
}


int getLength(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while(temp!= NULL) {
        cnt++;
        temp = temp->next;
    } 
    
    return cnt;

}


void insertAtHead(Node* &head, Node* &tail, int data) {
    // LL is empty
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }

    else {
        Node* newNode = new Node(data);
        newNode->next  = head;
        head->prev = newNode;
        head = newNode;
    }
}


void insertAtTail(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    } 

    else {
        // LL is non empty
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int data, int postion) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }

    else {
        int len = getLength(head);
        if(postion == 1) {
            insertAtHead(head, tail, data);
        }

        else if(postion == len+1) {
            insertAtTail(head, tail, data);
        }

        else {
            
        }
    }
}

int main() {

    // Node* head = new Node(10);

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtTail(head, tail, 1000);

    printLL(head);



    return 0;
}