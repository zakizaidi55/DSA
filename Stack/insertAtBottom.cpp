#include<iostream>
#include<stack>
using namespace std;


void insertAtBottom(stack<int>& st, int element) {
    // base case
    if(st.empty() || st.size() == 0)
        st.push(element);

    // recursion case
    int temp = st.top();
    st.pop();
    insertAtBottom(st, element);

    // backtracking
    st.push(temp);
}

int main() {

    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    int element = 300;

    insertAtBottom(st, element);

    cout << "he;;p jiii ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;

}