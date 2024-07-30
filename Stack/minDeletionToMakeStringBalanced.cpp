class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int count = 0;
        for(int i=0; i<s.size(); i++) {
            char&ch = s[i];
            if(!st.empty() && (ch == 'a' && st.top() == 'b')) { //ba
                count++;
                st.pop();
            } 

            else {
                st.push(ch);
            }
        }

        return count;
    }
};