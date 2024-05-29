class Solution {
public:
    void addOne(string&s) {
        int i = s.length()-1;
        while(i >= 0 && s[i] == '1') {
            s[i] = '0';
            i--;
        }

        // catch -> agar saari bit zero ho gyi, it means we need to add extra one at the beginning
        if(i < 0)
            s = '1' + s;
        
        else
            s[i] = '1';
    }
    int numSteps(string s) {
        int operation = 0;
        while(s.length() > 1 ) {
            int n = s.size();
            if(s[n-1] == '0') {
                operation++;
                s.pop_back();
            }

            else {
                addOne(s);
                operation++;
            }
        }

        return operation;
    }
};