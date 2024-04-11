class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;

        vector<char>stk;

        for(auto ch: num) {
            while(k > 0 && !stk.empty() && stk.back() > ch) {
                stk.pop_back();
                k--;
            }

            
            stk.push_back(ch);
            
        }

        while(k > 0 ) {
            stk.pop_back();
            k--;
        }

        for(char ch: stk) {
            if(ans.empty() && ch == '0') {
                continue;
            }

            ans.push_back(ch);
        }


        return ans.empty() ? "0" : ans;
    }
};