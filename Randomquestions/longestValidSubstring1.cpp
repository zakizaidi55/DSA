class Solution {
public:
    bool checkBalance(vector<int>&freq) {
        int common = 0;
        for(int i=0; i<26; i++) {
            if(freq[i] == 0) 
                continue;
            
            else if(common == 0) 
                common = freq[i];
            
            else if(freq[i] != common)
                return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        int maxLength = 0;

        for(int i=0; i<s.size(); i++) {
            vector<int>freq(26, 0);
            for(int j=i; j<s.size(); j++) {
                freq[s[j] - 'a']++;
                if(checkBalance(freq)) {
                    maxLength = max(maxLength, j-i+1);
                }
            }
        }

        return maxLength;
    }
};


