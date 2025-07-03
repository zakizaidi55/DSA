class Solution {
public:
    char kthCharacter(int k) {
        string st = "a";

        while(st.length() < k) {
            int size = st.length();
            for(int i=0; i<size; i++) {
                char ch = st[i];
                char nextCh = ch == 'z' ? 'a' : ch + 1;
                st += nextCh;
            }
        }

        return st[k-1];
    }
};


