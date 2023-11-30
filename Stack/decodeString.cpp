class Solution {
public:
    string decodeString(string s) {
        stack<string>st;

        // traverse all the character
        for(auto ch:s) {
            if(ch == ']') {
                string stringToRepeat = "";
                while(!st.empty() && st.top() != "[") {
                    string top = st.top();
                    stringToRepeat += top;
                    st.pop();
                }
                st.pop();
                string numericToRepeat = "";
                while(!st.empty() && isdigit(st.top()[0])) {
                    numericToRepeat += st.top();
                    st.pop();
                } 

                reverse(numericToRepeat.begin(), numericToRepeat.end());

                int n = stoi(numericToRepeat);

                string currStringToRepeat = "";
                while(n--) {
                  currStringToRepeat += stringToRepeat;
                }

                st.push(currStringToRepeat);
            }

            else  {
                // converter the character in string
                string temp(1, ch);
                st.push(temp);
            }
        }

        string ans;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};