

class Solution {
public:
    int M = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        // unordered_map<char, int>mp;
        vector<int>mp(26, 0);

        for(auto&ch: s) 
            mp[ch - 'a']++;
        

        for(int count=1; count<=t; count++) {
            // unordered_map<char, int>temp;
            vector<int>temp(26, 0);

            for(int i=0; i<26; i++) {
                char ch = i + 'a';
                int freq = mp[i];   
                if(freq != 0) {
                    if(ch != 'z') {
                        temp[(ch+1) - 'a'] = (temp[(ch+1) - 'a'] + freq) % M;
                    }

                    else {
                        temp['a' - 'a'] = (temp['a' - 'a'] + freq) % M;
                        temp['b' - 'a'] = (temp['b' - 'a'] + freq) % M;
                    }
                }
                
            }

            mp = move(temp);
        }

        int result = 0;
        for(int i=0; i<26; i++) {
            result = (result + mp[i]) % M;
        }

        return (result) % M;
    }
};



