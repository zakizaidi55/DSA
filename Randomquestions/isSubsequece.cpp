class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p = 0;
        int q = 0;
        int lenS = s.length();
        int lenT = t.length();
        while(p < lenS && q < lenT) {
            while(q < lenT && s[p] != t[q]){
                q++;
            }
            if(s[p] == t[q]) {
                p++;
                q++;
            }
        }
        if(p == lenS)
            return true;    
        
        return false;
    }
};