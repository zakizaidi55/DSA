class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0].front();
        int maxi = arrays[0].back();
        int result = 0;

        for(int i=1; i<arrays.size(); i++) {
            int currMini = arrays[i].front();
            int currMaxi = arrays[i].back();

            result = max(result, max(abs(maxi-currMini), abs(mini-currMaxi)));

            mini = min(currMini, mini);
            maxi = max(currMaxi, maxi);
        }

        return result;
        
    }
};