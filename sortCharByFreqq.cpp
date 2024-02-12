class Solution {
public:

    string frequencySort(string s) {
        map<char, int>mp;
        string ans;
        for(int i=0; i<s.length(); i++) {
            mp[s[i]]++;
        }

        vector<pair<int, char> >v;
        for(auto it=mp.begin(); it!=mp.end(); it++) {
            v.push_back(make_pair(it->second, it->first));
        }

        sort(v.begin(), v.end(), greater<>());
        for(auto it: v) {
            while(it.first--) {
                ans.push_back(it.second);
            }
        }

        return ans;
        
    }
};
