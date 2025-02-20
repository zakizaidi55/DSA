class Solution {
public:
    string solve(unordered_map<string, bool>&mp, string&curr,int&n) {
        // base case
        if(curr.length() == n) {
            if(mp.find(curr) == mp.end()) {
                //not found in map
                return curr;
            }

            return "";
        }

        // solve 1 case
        for(int i=0; i<=1; i++) {
            char ch = i + '0';
            curr.push_back(ch);

            // recursion call
            string recAns = solve(mp, curr, n);
            if(!recAns.empty()) {
                return recAns;
            }

            // backtrack
            curr.pop_back();
        }
        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        // humko ek binary string bnani hai, n length ki jo nums m present na ho
        unordered_map<string, bool> mp;

        for(auto&str:nums) {
            mp[str] = true;
        }

        string curr = ""; // I will create ans in curr and return it
        return solve(mp, curr, n);
        
    }
};