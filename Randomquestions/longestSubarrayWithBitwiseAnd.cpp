class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = 0;
        int result = INT_MIN;
        int streak = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > maxElement) {
                maxElement = nums[i];
                streak = 1;
                result = 1;
            }

            else if(nums[i] == maxElement )
                streak++;

            else 
                streak = 0;
            
            result = max(result, streak);
        }

        return result;
    }
}

;
