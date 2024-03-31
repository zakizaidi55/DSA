class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        for(int i=0; i<nums.size(); i++) {
            int mini = INT_MAX;
            int maxi = INT_MIN;
            for(int j=i; j<nums.size(); j++) {
                mini = min(nums[j], mini);
                maxi = max(nums[j], maxi);

                if(mini == minK && maxi == maxK) {
                    ans++;
                }

            }
        }

        return ans;
    }
};