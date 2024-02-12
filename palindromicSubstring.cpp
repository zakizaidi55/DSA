class Solution {
public:
    int checkAround(string&s, int leftIndex, int rightIndex) {
        int count = 0;
        while(leftIndex >= 0 && rightIndex < s.size() && s[leftIndex] == s[rightIndex]) {
            count++;
            leftIndex--;
            rightIndex++;
        }

        return count;
    }
    int countSubstrings(string s) {
        int totalCount = 0;

        for(int i=0; i<s.size(); i++) {
            int oddIndexAns = checkAround(s, i, i);
            int evenIndexAns = checkAround(s, i, i+1);

            totalCount = totalCount + oddIndexAns + evenIndexAns;
        }

        return totalCount;

    }
};
