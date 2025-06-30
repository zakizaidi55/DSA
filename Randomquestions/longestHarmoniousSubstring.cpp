class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxAns = 0;
        int left = 0;
        int right = 0;
        int ans = 0;
        while(right < nums.size()) {
            if(nums[right] - nums[left] == 1) {
                ans = right - left + 1;
                maxAns = max(ans, maxAns);
            }

            else if(nums[right] - nums[left] > 1) {
                while(nums[right] - nums[left] > 1) {
                    left++;
                }
            }

            right++;
        }

        return maxAns;
    }
};


