#include<iostream>
#include<stack>

using namespace std;


bool checkReduntant(string& str) {
    stack<char>st;
    for(int i=0; i<str.size(); i++) {
        char ch = str[i];
        if(ch == '(' || ch == '+' || ch == '*' || ch == '-' || ch == '/') {
            st.push(ch);
        }

        else if(ch == ')') {
            int operatorCount = 0;
            while(!st.empty() && st.top() != '(') {
                char temp = st.top();
                if(temp == '+' || temp == '-' || temp == '*' || temp =='/') {
                    operatorCount++;
                }
                st.pop();
            }

            // yha pat tabhi phochege jab stack is empty ya open bracket
            st.pop();

            if(operatorCount == 0)
                return true;
        }

    }

    return false;
}
int main() {

    string str = "(((a+b))*(c+d))";

    bool ans = checkReduntant(str);


    if(ans) {
        cout << "Reduntant bracket is present" << endl;

    }

    else{
        cout << "Reduntant bracket is not present " << endl;
    }

    return 0;
}