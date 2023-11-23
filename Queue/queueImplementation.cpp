#include<iostream>

using namespace std;

class Queue {
    public:
        int *arr;
        int size;
        int front;
        int rear;


        // constructor
        Queue(int size) {
            arr = new int[size];
            this->size = size;
            this->front = -1;
            this->rear = -1;
        }

        void push(int val) {
            // check full
            if(rear == size - 1) {
                cout << "Queue is overflow " << endl; 
            }

            else if(front == -1 && rear == -1){
                // empty case
                front++;
                rear++;
                arr[rear] = val;

            }

            else {
                rear++;
                arr[rear] = val;
            }
        }


        void pop() {
            // underflow 
            if(front == -1 && rear == -1) {
                cout << "queue is underflow "<< endl;
                return;
            }

            else if (front == rear){
                // single element
                arr[front] = -1;
                front = -1;
                rear = -1;
            }

            else {
                // normal case
                arr[front] = -1;
                front++ ;
            }
        }

        bool isEmpty() {
            if(front == -1 && rear == -1) 
                return true;
        

            else {
                return false;
            }
        }


        int getSize() {
            if(front == -1 && rear == -1) 
                return 0;
            else 
                return rear-front+1;
        }

        int getFront() {
            if(front == -1) {
                // no element in queue
                return -1;
            }

            else {
                return arr[front];
            }
            
        }

        int getRear() {
            if(rear == -1) {
                // no element is present
                return -1;
            }

            else 
                return arr[rear];

        }

// this function is for us to see all the function is working or not    
        void print() {
            cout << "Printing queue: "<< endl;
            for(int i=0; i<size; i++) {
                cout << arr[i] << " ";
            }

            cout << endl;
        }

        
};

int main() {

    // creating queue
    Queue q(5);
    q.print();

    q.push(10);
    q.print();

    q.push(20);
    q.print();

    q.push(30);
    q.print();

    q.push(40);
    q.print();
    
    q.push(50);
    q.print();


    cout << "size of queue " << q.getSize() << endl;


    q.pop();

    q.print();

    cout << "size of queue after pop " << q.getSize() << endl;

    q.push(100);
    q.print();

    return 0;
}