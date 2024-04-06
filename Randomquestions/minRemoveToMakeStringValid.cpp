class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<bool>vis(n, 1);
        stack<int>st; //invalid index
        for(int i=0; i<n; i++) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                continue;
            }

            if(s[i] == '(') {
                st.push(i);
            }

            else {
                if(!st.empty()) {
                    st.pop();
                }

                else {
                    vis[i] = 0;
                }
            }
        }

        // if any close bracket comes first or any open remaining bracket
        while(!st.empty()) {
            vis[st.top()] = 0;
            st.pop();
        }

        string ans = "";

        for(int i=0; i<n; i++) {
            if(vis[i] == 1) {
                ans.push_back(s[i]);
            }
        }

        return ans;

    }
};