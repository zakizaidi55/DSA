class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int x = -1; // it track ki humko 1 mismatch index mil gya hai
        for(int i=0; i<s1.size(); i++) {
            if(s1[i] != s2[i]) {
                if(x == -1) //first mismatch index
                    x = i;
                
                else {
                    // swap karke x ko i se check karna h
                    swap(s2[x],s2[i]);
                    return s1 == s2;
                }
            }
        }

        return s1 == s2;
    }
};