class Solution {
public:
    void solve(string& s,unordered_set<string>&ans, int open, int close, int bal, int index, string& output) {
        // base case
        if(index >= s.length()) {
            // valid ans
            if(open == 0 && close == 0 && bal == 0) {
                ans.insert(output);
            }

            return;
        }

        if(s[index] != '(' && s[index] != ')') {
            output.push_back(s[index]);
            solve(s, ans, open, close, bal, index+1, output);

            // backtrack
            output.pop_back();
        }

        else {
            // brackets
            // 2 case -> (  and )
            // open bracket
            if(s[index] == '(') {
                // inc/exc
                // remove
                if(open > 0) {
                    solve(s, ans, open-1, close, bal, index+1, output);
                }

                // not remove
                output.push_back('(');
                solve(s, ans, open, close, bal+1, index+1, output);

                output.pop_back();
            }   

            else if(s[index] == ')') {
                // remove karu
                if(close > 0) {
                    solve(s, ans, open, close-1, bal, index+1, output);
                }

                // not remove
                // catch-> yha galti hoti hai
                // aap ek closed bracket par khade ho and previously koi open bracket present nhibh
                // toh kya m ise remove na karu
                if(bal > 0) {
                    output.push_back(')');
                    solve(s, ans, open, close, bal-1, index+1, output);
                    output.pop_back();
                }
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string>ans;
        int invalidOpen = 0;
        int invalidClose = 0;
        int balance = 0;   
        int index = 0;
        string output = "";

        for(auto ch: s) {
            if(ch == '(') {
                invalidOpen++;
            }

            else if(ch == ')') {
                if(invalidOpen > 0) {
                    invalidOpen--;
                }

                else {
                    invalidClose++;
                }
            }
        }

        solve(s, ans, invalidOpen, invalidClose, balance, index, output);
        return vector<string>(ans.begin(), ans.end());
    }
};