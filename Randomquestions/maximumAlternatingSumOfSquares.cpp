class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            nums[i] = nums[i] * nums[i];
        }

        long long ans = 0;
        sort(nums.begin(), nums.end());

        long long largeHalf = accumulate(nums.begin()+n/2, nums.end(), 0LL);
        long long smallHalf = accumulate(nums.begin(), nums.begin()+n/2, 0LL);

        return largeHalf - smallHalf;
    }
};


