class Solution {
public:
    std::array<int, 256> hash(string s) {
        std::array<int,256> hash = {0};
        for(int i=0; i<s.size(); i++) {
            hash[s[i]]++;
        }

        return hash;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<std::array<int, 256>, vector<string> >mp;

        for(auto str: strs) {
            mp[hash(str)].push_back(str);
        } 
        vector<vector<string> >ans;

        for(auto i=mp.begin(); i!=mp.end(); i++) {
            ans.push_back(i->second);
        }

        return ans;
    }
};