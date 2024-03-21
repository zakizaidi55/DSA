class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        int i, n = s.length();
        for(i = 0; i < n; i++)
            mp[s[i]]++;
        
        vector<pair<int, char> > vec;
        for(auto itr = mp.begin(); itr != mp.end(); itr++)
            vec.push_back({itr->second, itr->first});
        
        sort(vec.begin(), vec.end(), greater<>());
        string ans;
        
        for(pair<int, char> e : vec){
            while(e.first--)
                ans.push_back(e.second);
        }
        
        return ans;
    }
};