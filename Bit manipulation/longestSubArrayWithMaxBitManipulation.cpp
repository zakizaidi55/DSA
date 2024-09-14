class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = 0;
        int result = INT_MIN;
        int streak = 0;

        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];

            if(num > maxElement) {
                maxElement = num;
                streak = 0;
                result = 0;
            }

            if(num == maxElement) {
                streak++;
            }

            else {
                streak = 0;
            }

            result = max(result, streak);
        }

        return result;
    }
};