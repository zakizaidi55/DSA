class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            int number = nums[i];
            nums[i] = number*number;
        }

        sort(nums.begin(), nums.end());

        return nums;
    }
};