class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans(nums.size(), -1);
        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];
            if(nums[i] == 2)
                continue;
            
            for(int j=1; j<=num; j++) {
                int nextNum = j+1;
                if((j | nextNum )== num){
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};
