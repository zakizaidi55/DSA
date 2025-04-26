class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minB = -1;
        int maxB = -1;
        int badB = -1;
        long long count = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < minK || nums[i] > maxK) {
                badB = i;
            }

            if(nums[i] == minK) {
                minB = i;
            }

            if(nums[i] == maxK) {
                maxB = i;
            }

            int toBeAdded = min(minB, maxB) - badB;

            count += max(0, toBeAdded);
        }

        return count;
    }
};



