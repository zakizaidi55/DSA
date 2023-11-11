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






// ++++++++++++++++++++++++++=Method 2+++++++++++++++++++++++++++++++++++++

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int i = 0;
        int j = 0;
        int n = s.size();
        vector<int>count(n);

        while(j < n) {
            s[i] = s[j];
            count[i] = 1;
            if(i > 0 && s[i] == s[i-1])
                count[i] += count[i-1];
            
            if(count[i] == k)
                i -= k;
            
            i++;
            j++;
        }

        return s.substr(0,i);
    }
};