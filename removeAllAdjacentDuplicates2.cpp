class Solution {
public:
    bool lastK_1CharAreSame(string& ans, char& newCh, int k_1) {
        int it = ans.size() - 1;
        for(int i=0; i<k_1; i++) {
            if(newCh != ans[it]) {
                return false;   
            }
            it--;
        }

        return true;
    }
    string removeDuplicates(string s, int k) {
        string ans = "";
        for(int i=0; i<s.size(); i++) {
            char newCh = s[i];
            if(ans.size() < k-1) {
                ans.push_back(newCh);
            }

            else {
                if(lastK_1CharAreSame(ans, newCh, k-1)) {
                    for(int i=0; i<k-1; i++) {
                        ans.pop_back();
                    }
                }

                else {
                    ans.push_back(s[i]);
                }
            }
        }
        return ans;
    }
};