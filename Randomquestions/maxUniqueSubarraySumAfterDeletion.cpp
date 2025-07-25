class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int>v(101, -1);
        int res = 0;
        int negativeNum = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] <= 0) {
                // negative number, in that case we need to keep track of smallest negative number
                negativeNum = max(negativeNum, nums[i]);
            }
            else if(v[nums[i]] == -1) {
                res += nums[i];
                v[nums[i]] = 1;
            }
        }

        return res == 0 ? negativeNum : res;
    }
};


