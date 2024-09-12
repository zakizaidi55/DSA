class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>st;
        int count = 0;
        for(int i=0; i<allowed.size(); i++) {
            st.insert(allowed[i]);
        }

        for(auto str: words) {
            bool isFound = true;
            for(int i=0; i<str.size(); i++) {
                char ch = str[i];
                if(st.find(ch) == st.end()) {
                    // not found
                    isFound = false;
                    break;
                }
            }

            if(isFound) {
                count++;
            }
        }

        return count;
    }

};