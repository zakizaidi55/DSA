class Solution {
public:
    int solve(string s, pair<char, vector<int>> p){
        if(p.second.size() == 1) 
            return 0;

        unordered_set<char> unique;
        int l = p.second[0];
        int h = p.second[p.second.size()-1];

        for(int i=l+1; i<h; i++){
            unique.insert(s[i]);
        }
        
        return unique.size();
    }
    int countPalindromicSubsequence(string s) {
        unordered_map<char,vector<int>> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]].push_back(i);
        }
        int ans=0;
        for(auto it:mp)
            ans += solve(s, it);

        return ans;
    }
};