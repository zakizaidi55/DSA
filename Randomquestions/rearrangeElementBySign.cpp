class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int positiveIndex = 0;
        int negativeIndex = 1;
        int index = 0;
        
        for(int i=0; i<n; i++) {
            if(nums[i] >= 0) {
                ans[positiveIndex] = nums[i];
                positiveIndex += 2;
            }
        }
        for(int i=0; i<n; i++) {
            if(nums[i] < 0) {
                ans[negativeIndex] = nums[i];
                negativeIndex += 2;
            }
        }


        return ans;
    }
};