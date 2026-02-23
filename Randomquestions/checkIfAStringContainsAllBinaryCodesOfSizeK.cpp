class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int totalBinarySize = (1 << k);
        unordered_set<string>st;

        for(int i=k; i<=s.size(); i++) {
            string sub = s.substr(i-k, k);
            if(!st.count(sub)) {
                st.insert(sub);
                totalBinarySize--;
            }

            if(totalBinarySize == 0) 
                return true;
        }

        return false;
    }
};


