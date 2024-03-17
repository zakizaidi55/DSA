class Solution {
public:
    void solve(string mapping[], string output, int index, vector<string>&ans, string str) {
        // base case
        if(index >= str.length()) {
            // output me string ban chuki hogi store that ans in ans array
            // catch->ho sakta hai empty string ban rahi ho
            if(output.length() > 0) {
                ans.push_back(output);
            }
            
            return;
        }

        string temp = mapping[str[index]-'0'];
            for(auto ch: temp) {
                output.push_back(ch);
                solve(mapping, output, index+1, ans, str);
                // backtrack
                output.pop_back();
            }
    }
    vector<string> letterCombinations(string digits) {
        string mapping[] = {"","", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        string output = "";
        int index = 0;
        vector<string>ans;
        solve(mapping, output, index, ans, digits);
        return ans;
    }
};