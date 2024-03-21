class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for(int i=0; i<=n-m; i++) {
            for(int j=0; j<m; j++) {
                if(needle[j] != haystack[i+1]) {
                    break;
                }
                
                if(j = m-1) 
                    return i;
            }
        }

        return -1;
    }
};


// =---------------------Method 2---------------------=

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.size();
        int i = 0;
        int size = haystack.size() - len  + 1;
        while(i <= size){
            if(haystack.substr(i, len) == needle)
                return i;
            
            i++;
    }
        return -1;
    }
};