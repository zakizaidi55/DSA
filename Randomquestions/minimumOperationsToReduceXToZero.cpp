class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if(totalSum == x)
            return n;
        
        if(totalSum < x)
            return -1;
        
        // ab mujhe ek longest window find karni hai jiska sum ho (totalSum - x) ke
        int target = totalSum - x;

        int left = 0;
        int maxLen = -1;
        int currSum = 0;

        for(int right=0; right<n; right++) {
            currSum += nums[right];

            while(currSum > target) 
                currSum -= nums[left++];

            if(currSum == target)
                maxLen = max(maxLen, right-left+1);
        }

        return maxLen == -1 ? -1: n-maxLen;
    }
};
