class Solution {
public:
    string processStr(string s) {
        string ans;
        for(char ch: s) {
            if(ch >= 'a' && ch <= 'z') {
                ans.push_back(ch);
            }

            else if(ch == '*' && ans.size() >= 1) {
                ans.pop_back();
            }

            else if(ch == '#' && ans.size() >= 1) {
                string oldResult = ans;
                ans = ans + oldResult;
            }

            else if(ch == '%' && ans.size() >= 1) {
                reverse(ans.begin(), ans.end());
            }
        }

        return ans;
    }
};


