class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>smallFreq(26, -1);
        vector<int>largeFreq(26, -1);
        int count = 0;

        for(int i=0; i<word.size(); i++) {
            char ch = word[i];

            if(islower(ch)) {
                smallFreq[ch - 'a'] = i;
            }

            else {
                if(largeFreq[ch - 'A'] == -1) {
                    largeFreq[ch - 'A'] = i;
                }
            }
        }

        for(int i=0; i<26; i++) {
            if(smallFreq[i] != -1 && largeFreq[i] != -1 && smallFreq[i] < largeFreq[i]) {
                count++;
            }
        }

        return count;
    }
};


