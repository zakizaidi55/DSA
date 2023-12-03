#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void reverseQueue(queue<int>& q) {
    stack<int>s;
    while(!q.empty()) {
        int frontElement = q.front();
        q.pop();

        s.push(frontElement);
    }

    while(!s.empty()) {
        int topElement = s.top();
        s.pop();

        q.push(topElement);
    }
}

void reverseRec(queue<int>&q) {
    if(q.empty()) {
        return;
    }

    int element = q.front();
    q.pop();

    reverseQueue(q);
    q.push(element);

}


void interLeaveQueue(queue<int>& first) {
    queue<int>second;
    // push first half of first queue in second queue
    int size = first.size();
    for(int i=0; i<size/2; i++) {
        int temp = first.front();
        first.pop();

        second.push(temp);
    }


    // merge both the halfes
    // into the original queue

    for(int i=0; i<size/2; i++) {
        int temp = second.front();
        second.pop();
        first.push(temp);

        temp = first.front();
        first.pop();
        first.push(temp);
    }
}

void reverseFirstKElement(queue<int>&q, int k) {
    stack<int>s;
    int n = q.size();

    if(k > n || k ==0)
        return;
    for(int i=0; i<k; i++) {
        int temp = q.front();
        q.pop();
        s.push(temp);
    }

    while(!s.empty()) {
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    for(int i=0; i<n-k; i++) {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}


void printFirstNegative(int* arr, int n, int k) {
    deque<int>dq;

    // process first k element
    for(int index=0; index<k; index++) {
        int element = arr[index];
        if(element < 0) {
            dq.push_back(index);
        }
    }

    // process remaining window -> removal and addition
    for(int index=k; index<n; index++) {
        // find the answer from old window
        
        if(dq.empty()) {
            cout << "0 " << " ";
        }

        else {
            cout << arr[dq.front()] << " ";
        }
       

        // removal - jo bhi index out of range h usko queue se remove kardo

        if(index - dq.front() >= k) {
            dq.pop_front();
        }

        // addition

        if(arr[index] < 0) {
            dq.push_back(index);
        }
    }   

   // last window k answer print 
    if(dq.empty()) {
        cout << "0 " << " ";
    }

    else {
        cout << arr[dq.front()] << " ";
    }
}

int main() {
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    int arr[] = {2,-5,4,-1,-2,0,5};
    int size = 7;
    int k = 3;

    printFirstNegative(arr, size, k); 

    // reverseFirstKElement(q,4);

    // reverseRec(q);

    // interLeaveQueue(q);

    // cout << "printing queue " << endl;
    // while(!q.empty()) {
    //     int element = q.front();
    //     q.pop();
    //     cout << element << " " ;
    // } 
}