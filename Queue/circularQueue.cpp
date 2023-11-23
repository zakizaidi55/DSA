#include<iostream>

using namespace std;

class CircularQueue{
    public:
        int* arr;
        int size;
        int front;
        int rear;

        CircularQueue(int size) {
            arr= new int[size];
            front = -1;
            rear = -1;
            this->size = size;
        }


        void push(int val) {
            // overflow
            // empty case
            // circular nature
            // normal flow
            if((front == 0 && rear == size-1) || (rear == front-1)) {
                cout <<"overflow " << endl;
            }

            else if(front == -1 && rear == -1) {
                front++;
                rear++;
                arr[rear] = val;
            }

            else if(rear == size-1 && front != 0) {
                rear = 0;
                arr[rear] = val;
            }

            else {
                rear++;
                arr[rear] = val;
            }

        }

        void pop() {
            // underflowflow
            // single element case
            // circular nature
            // normal flow

            if(front == -1 && rear == -1 ) {
                cout << "underflow " << endl;
                return;
            }

            else if(front == rear ) {
                arr[front] = -1;
                front = -1;
                rear = -1;
            }

            else if(front == size-1) {
                arr[front] = -1;
                front = 0;
            }

            else {
                arr[front] = -1;
                front++;
            }
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

    return 0;
}