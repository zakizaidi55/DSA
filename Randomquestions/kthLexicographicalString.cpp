class Solution {
public:
    void solve(int n, string&curr, vector<string>&result) {
        if(curr.length() == n) {
            result.push_back(curr);
            return;
        }

        for(char ch='a'; ch<='c'; ch++) {
            // check for the condition like i != i+1
            if(!curr.empty() && curr.back() == ch) 
                continue;
            
            // do
            curr.push_back(ch);

            solve(n, curr, result);

            // backtrack
            curr.pop_back();
        }
    }


    string getHappyString(int n, int k) {
        string curr = "";
        vector<string>result;

        solve(n, curr, result);
        if(result.size() < k)
            return "";
        return result[k-1];
    }
};