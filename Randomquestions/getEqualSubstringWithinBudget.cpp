class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int j = 0;
        int i = 0;
        int length = INT_MIN;
        int currCost = 0;
        while(j < n) {
            currCost += abs(s[j] - t[j]);


            while(currCost > maxCost) {
                currCost -= abs(s[i] - t[i]);
                i++;
            }
            
            int currLength = j-i+1;

            length = max(length, currLength);
            j++;
            
        }

        return length;
    }
};