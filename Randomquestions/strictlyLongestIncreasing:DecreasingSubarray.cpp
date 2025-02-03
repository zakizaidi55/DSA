class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                count++;
                ans = max(ans, count);
            }

            else 
                count = 0;
        }
        count = 0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] < nums[i-1]) {
                count++;
                ans = max(ans, count);
            }

            else 
                count = 0;
        }

        return ans+1;
    }
};