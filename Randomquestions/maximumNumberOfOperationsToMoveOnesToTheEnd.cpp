class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int operations = 0;
        int oneCount = 0;
        int i = 0;

        while(i < n) {
            if(s[i] == '0') {
                operations += oneCount;
                while(i < n && s[i] == '0') 
                    i++;
            }

            else {
                oneCount++;
                i++;
            }
        }

        return operations;
    }
};


