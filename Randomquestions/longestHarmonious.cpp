class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            int count = 0;
            bool isHarmonic = false;
            for(int j=0; j<nums.size(); j++){
                if(nums[j] == nums[i]){
                    count++;
                }
                else if(nums[j]+1 == nums[i]){
                    count++;
                    isHarmonic = true;
                }
            }
            if(isHarmonic) 
                ans = max(ans, count);
        }
        return ans;
    }
};