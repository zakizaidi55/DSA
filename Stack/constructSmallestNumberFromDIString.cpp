class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        
        string num = "";
        int counter = 1;
        stack<char>st;

        for(int i=0; i<=9; i++) {
            st.push(counter + '0');
            counter++;

            if(i == n || pattern[i] == 'I') {
                while(!st.empty()) {
                    num.push_back(st.top());
                    st.pop();
                }
            }
        }

        return num;
    }
};