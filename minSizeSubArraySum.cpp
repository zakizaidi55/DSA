class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int mini = INT_MAX;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            int count = 0;
            int sum = 0;
            for(int j = i; j < len; j++){
                sum += nums[j];
                count++;
                if(sum >= target) 
                    mini = min(mini, count);
            }
        }
        return (mini == INT_MAX) ? 0: mini;
    }
};