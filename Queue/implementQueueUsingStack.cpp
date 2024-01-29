class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int poppedElement = -1;
        if(!s2.empty() ) {
            poppedElement = s2.top();
        }

        else {
            while(!s1.empty()) {
                int element = s1.top();
                s2.push(element);
                s1.pop();
            }

            poppedElement = s2.top();
        }
        s2.pop();
        return poppedElement;
    }
    
    int peek() {
        int front = -1;
        if(!s2.empty() ) {
            front = s2.top();
        }

        else {
            while(!s1.empty()) {
                int element = s1.top();
                s2.push(element);
                s1.pop();
            }
            front = s2.top();
        }

        return front;
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */