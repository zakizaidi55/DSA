#include<iostream>
#include<deque>
using namespace std;

class Dequeue{
    public:
        int* arr;
        int size;
        int front;
        int rear;

        Dequeue(int size) {
            arr = new int[size];
            this->size = size;
            front = -1;
            rear = -1;
        }


        void pushBack(int val) {
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


        void pushFront(int val) {
            if((front == 0 && rear == size-1) || (rear == front-1))  {
                cout <<" Overflow " << endl;
                return;
            }

            else if(front == -1 && rear == - 1) {
                front++;
                rear++;
                arr[front] = val;
            }

            else if(front == 0 && rear != size-1) {
                front = size-1;
                arr[front] = val;
            }

            else {
                front--;
                arr[front] = val;
            }
        }

        void popFront() {
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

        void popBack() {
            // underflow
            // single element
            // normal flow
            if(front == -1 && rear == -1) {
                cout << "underflow " << endl;
                return;
            }

            else if(front == rear) {
                arr[rear] = -1;
                front = -1;
                rear = -1;
            }

            else if(rear == 0) {
                arr[rear] = -1;
                rear = size - 1;
            }

            else {
                arr[rear] = -1;
                rear--;
            }
        }
};


int main() {


    // deque<int>dq;
    // dq.push_back(10);
    // cout << dq.front() << endl;
    // return 0;
}