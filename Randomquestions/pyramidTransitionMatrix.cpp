class Solution {
public:
    unordered_map<string, bool>dp;
    bool solveUsingRec(string curr, unordered_map<string, vector<char> >&mp, int index, string above) {
        if(curr.length() == 1)
            return true;
        
        string key = curr + "_" + to_string(index) + "_" + above;

        if(dp.count(key))
            return dp[key];
        
        if(index == curr.length()-1) 
            return dp[key] = solveUsingRec(above, mp, 0, "");
        
        string pair = curr.substr(index, 2);

        if(mp.find(pair) == mp.end()) 
            return dp[key] = false;
        

        for(auto&ch: mp[pair]) {
            // do
            above.push_back(ch);

            // explore
            if(solveUsingRec(curr, mp, index+1, above) == true)
                return dp[key] = true;
            
            // backtrack
            above.pop_back();

        }

        return dp[key] = false;
        
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char> >mp;

        // store all the allowed character like
        // BC->C,
        for(auto&str: allowed) {
            mp[str.substr(0,2)].push_back(str[2]);
        }

        return solveUsingRec(bottom, mp, 0, "");
    }
};


