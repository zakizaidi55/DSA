#include<iostream>
#include<stack>
using namespace std;

class Stack{

    public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size) {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;

    }


    void push1(int data) {
        if(top2- top1 == 1) {
            cout <<"overflow " << endl;
            return;
        }

        else {
        top1++;
        arr[top1] = data;
        }
     
    }
    

    void push2(int data) {
        if(top2-top1 == 1) {
            cout << "Overflow "<< endl;
            return;
        }

        else {
            top2--;
            arr[top2] = data;
        }

    }

    void pop1() {
        if(top1 == -1) {
            cout <<"stack 1 is empty underflow" << endl;
            return;
        }

        else {
            arr[top1] = 0;
            top1--;
        }


    }


    void pop2() {

        if(top2 == size ){
            cout <<"stack 2 is empty underflow" << endl;
            return;
        }

        else {
            arr[top2] = 0;
            top2++;
        }
        
    }

};

int main() {

    Stack s(10);
    s.push1(10);

    return 0;
}