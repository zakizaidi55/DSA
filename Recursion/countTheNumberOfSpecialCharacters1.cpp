class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>capsFreq(26, 0);
        int count = 0;
        for(int i=0; i<word.size(); i++) {
            char ch = word[i];
            if(ch >= 'A' && ch <= 'Z')
                capsFreq[ch - 'A']++;
        }

        for(int i=0; i<word.size(); i++) {
            char ch = word[i];
            if(ch >= 'a' && ch <= 'z') {
                if(capsFreq[ch - 'a'] >= 1) {
                    count++;
                    capsFreq[ch - 'a'] = 0;
                }
            }
        }


        return count;
    }
};


