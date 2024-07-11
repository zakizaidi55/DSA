class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') 
                st.push(i);
            
            else if(s[i] == ')') {
                int start = st.top() + 1;
                int end = i;

                reverse(s.begin()+start, s.begin()+end);
                st.pop();
            }
        }

        string ans = "";
        for(auto ch: s) {
            if(ch != '(' && ch != ')') 
                ans += ch;
        }

        return ans;
    }
};