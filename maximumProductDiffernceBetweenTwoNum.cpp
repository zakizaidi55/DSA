class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int firstMaxNum = nums[nums.size()-1];
        int secondMaxNum = nums[nums.size()-2];

        int firstSmallNum = nums[0];
        int secondSmallNum = nums[1];

        int ans = (firstMaxNum*secondMaxNum) - (firstSmallNum*secondSmallNum);

        return ans;
    }
};