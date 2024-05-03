class Solution {
public:
    int compareVersion(string version1, string version2) {
        for(int i=0, j=0; (i<version1.size() || j < version2.size()); i++, j++) {
            long long value1 = 0;
            long long value2 = 0;

            while(i < version1.size() && version1[i] != '.') {
                value1 = value1 * 10 + version1[i]-'0';
                i++;
            }

            while(j < version2.size() && version2[j] != '.') {
                value2 = value2*10 + version2[j] - '0';
                j++;
            }

            if(value1 < value2) {
                return -1;
            }

            if(value1 > value2) {
                return 1;
            }
        }

        return 0;
    }
};