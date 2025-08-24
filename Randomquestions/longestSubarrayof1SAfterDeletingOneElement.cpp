class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int lastZeroIndex = -1;
        int i = 0;
        int j = 0;
        int result = 0;
        while(j < nums.size()) {
            if(nums[j] == 0) {
                i = lastZeroIndex + 1;
                lastZeroIndex = j;
            }

            result = max(result, j-i);
            j++;
        }

        return result;
    }
};


