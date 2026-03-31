class Solution {
public:
    bool sameWord(string&word, string&str, int i, int m)  {
        for(int j=0; j<m; j++) {
            if(word[i] != str[j]) {
                return false;
            }
            i++;
        }

        return true;
    }
    
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        int resultLength = n+m-1;
        string word(resultLength, '$');

        vector<bool>canChange(resultLength, false);

        // process 'T' first
        for(int i=0; i<n; i++) {
            if(str1[i] == 'T') {
                int i_ = i;
                for(int j=0; j<m; j++) {
                    if(word[i_] != '$' && word[i_] != str2[j])
                        return "";

                    word[i_] = str2[j];
                    i_++;
                }
            }
        }

        // fill the remaining spaces with 'a'
        for(int i=0; i<resultLength; i++) {
            if(word[i] == '$') {
                word[i] = 'a';
                canChange[i] = true;
            }
        }

        // process 'F'
        for(int i=0; i<n; i++) {
            if(str1[i] == 'F') {
                if(sameWord(word, str2, i, m)) {
                    // if same, then we need to make it unequal
                    bool changed = false;
                    for(int k=i+m-1; k>=i; k--) {
                        if(canChange[k] == true) {
                            word[k] = 'b';
                            changed = true;
                            break;
                        }
                    }

                    // i was not able to change the equality
                    if(!changed) 
                        return "";
                }
            }
        }

        return word;
    }
};


