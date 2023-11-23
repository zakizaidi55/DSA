#include<iostream>
#include<queue>


using namespace std;

int main() {
    queue<int>q;
    // insertion
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);

    cout << "size of queue is " << q.size() << endl;; 


    if(q.empty()) {
        cout << "Queue is empty " << endl;
    }

    else {
        cout <<"queue is not empty " << endl;
    }


    // removal
    q.pop();

    cout << "size of queue is " << q.size() << endl;; 


    if(q.empty()) {
        cout << "Queue is empty " << endl;
    }

    else {
        cout <<"queue is not empty " << endl;
    }

    cout << "front of the queue is " << q.front() << endl;
    cout << "last element of the queue is " << q.back() << endl;   

    return 0;
}