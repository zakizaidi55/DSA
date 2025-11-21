class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>charSet;
        int n = s.length();
        int result = 0;
        for(char ch: s) {
            charSet.insert(ch);
        }

        // ab humko jitne bhi char set m sabka first and last index find karna h
        // then phr dekhna h ki unko bich m kitne char available h jo unique subseq bana rahe h

        for(char ch: charSet) {
            int leftIndex = -1;
            int rightIndex = -1;

            for(int i=0; i<n; i++) {
                if(s[i] == ch) {
                    if(leftIndex == -1) {
                        leftIndex = i;
                    }

                    rightIndex = i;
                }
            }

            // ab hum inke bich ke char dekhege kitne unique subseq bann rahi h
            unordered_set<char>st;
            for(int middleIndex=leftIndex+1; middleIndex<=rightIndex-1; middleIndex++) {
                st.insert(s[middleIndex]);
            }

            result += st.size();
        }

        return result;
    }
};
