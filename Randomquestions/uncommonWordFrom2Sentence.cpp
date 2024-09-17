class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int>mp;
        int j = 0;
        for(int i=0; i<s1.size(); i++) {
            if(s1[i] == ' ') {
                mp[s1.substr(j, i-j)]++;
                j = i+1;
            }
        }
        mp[s1.substr(j, s1.size())]++;

        vector<string>ans;
        
        j = 0;
        for(int i=0; i<s2.size(); i++) {
            if(s2[i] == ' ') {
                string str = s2.substr(j, i-j);
                mp[str]++;
                j = i+1;
            }
        }

        string str = s2.substr(j, s2.size());
        
        mp[str]++;
        

        // now the final step, put answer in vector
        for(auto it: mp) {
            if(it.second == 1) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};