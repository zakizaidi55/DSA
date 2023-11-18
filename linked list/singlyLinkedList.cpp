#include<iostream>
using namespace std;


class Node {
    public:
    int data;
    Node* next;

    Node() {
        // cout << "I am inside deafault constructot " << endl;
        this->next = NULL;
    }

    Node(int data) {
        // cout << "I am inside parameterised constructor " << endl;
        this->data = data;
        this->next = NULL;
    }
    ~Node() {
        cout << "destructor is called " << this->data << endl; 
    }
};

void printLL(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    } 

    cout << endl;
}

int getLength(Node* head) {
    int cnt = 0;
    Node* temp = head;

    while(temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    
    return cnt;
}

// void createTail(Node* &head, Node* &tail) {
//     Node* temp = head;

//     while(temp->next != NULL) {
//         temp = temp->next;
//     }

//     // At the end of this loop out temp pointer is on the last Node of the linked list
//     tail = temp;
// }

// catch-> we have to pass head as pass by reference 
void insertAtHead(Node* &head, Node* &tail, int data) {

    if(head == NULL) {
        // create new Node
        Node* newNode = new Node(data);
        // update head
        head = newNode;
    }

    
    else {
        // create a new node
        Node* newNode = new Node(data);

        // attached the node to the head node
        newNode->next = head;

        // update head
        head = newNode;
    }
    
    
}


void insertAtTail(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        // create new Node
        Node* newNode = new Node(data);
        // update head and tail
        head = newNode;
        tail = newNode;
    }

    else {
        // create new node
        Node* newNode = new Node(data);
        // attached the new node to the tail
        cout << "Node is created " << endl;
        tail->next = newNode;
        cout << "node is attached " << endl;
        // update tail

        tail = newNode;
        cout << "tail is updated " << endl;
    }
}


void insertAtPosition(Node* &head, Node* &tail, int data, int position) {

    int length = getLength(head);

    if(position <= 1) { 
        insertAtHead(head, tail, data);
    }

    // catch -> jab hum ek node end m insert karte h toh last m lagti h
    // isliye yha par length + 1 kara taaki jab length se zyada ho tabhi last m isert ho
    else if(position  > length) {
        insertAtTail(head, tail, data);
    }
    
    else {
        // create a new Node
        Node* newNode = new Node(data);
        // traverse the curr and prev node to the positions
        Node* prev = NULL;
        Node* curr = head;

        while(position != 1) {
            prev = curr;
            curr = curr->next;
            position--;
        }

        // attached the prev node to the new node
        prev->next = newNode;
        
        // attached the new node to the curr
        newNode->next = curr;
    }

    
}

void deleteNode(Node* &head, Node* &tail, int position) {

    if(head == tail) {
        // single element case
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }

    if(head == NULL ) {
        cout <<"Cannot delete coz LL is empty" << endl;
        return;
    }

    int length = getLength(head);

    if(position == 1) {
        // first node ko delete
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;

    }

    else if(position == length) {
        // last position ko delete kar dena
        Node* prev = head;
        while(prev->next != tail) {
            prev = prev->next;
        }

        prev->next = NULL;

        delete tail;

        tail = prev;

    }


    else {
        // middle me se koi node kop delete karna hai

        // set prev and curr pointer
        Node* prev = NULL;
        Node* curr = head;

        while(position != 1) {
            position--;
            prev = curr;
            curr = curr->next;
        }

        // prev->next ko curr ke next
        prev->next = curr->next;

        // curr ke next ko null
        curr->next = NULL;

        // free memory
        delete curr;
    }
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
    // insertAtTail(head,tail,500);

    deleteNode(head, tail ,5);


    printLL(head);







    // creation of node
    // Node a;

    // creation of node dynamically
    // Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // Node* fourth = new Node(40);
    // Node* fifth = new Node(50);

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;

    // Node* head = first;
    // Node* tail = fifth;

    // printLL(head);
    // // cout << "Length of LL: " << getLength(head);
    // // insertAtHead(head,tail, 500);
    // insertAtTail(head,tail, 500);
    // printLL(head);



    return 0;
}