class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};
        queue<pair<char,int> >q;
        int ans = -1;
        for(int i=0; i<s.length(); i++) {
            char ch = s[i];
            freq[ch-'a']++;
            q.push({ch,i});
          
        }

        while(!q.empty()) {
            char frontChar = q.front().first;

            if(freq[frontChar-'a'] > 1) {
                q.pop();
            }

            else {
                ans = q.front().second;
                break;
            }
        }

        
        return ans;
    }
};