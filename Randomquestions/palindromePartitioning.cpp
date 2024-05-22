class Solution {
public:
    bool isPalindrome(string&s, int i, int j) {
        while(i < j) {
            if(s[i++] != s[j--]) {
                return false;
            }

        }

        
        return true;
    }
    void solveUsingRecursion(string&s, int index, vector<vector<string> >&ans, vector<string>curr) {

        if(index == s.size()) {
            ans.push_back(curr);
            return;
        }

        for(int i=index; i<s.size(); i++) {
            if(isPalindrome(s, index, i)) {
                curr.push_back(s.substr(index, i-index+1));
                solveUsingRecursion(s, i+1, ans, curr);
                curr.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string> >ans;
        vector<string>curr;

        solveUsingRecursion(s,0, ans, curr);

        return ans;
    }
};