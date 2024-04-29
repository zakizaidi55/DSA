class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        int temp = 0;
        for(int i=0; i<nums.size(); i++) {
            temp = temp^nums[i];
        }

        for(int i=0; i<32; i++) {
            if((k &(1 << i)) != (temp & (1 << i))) {
                ans++;
            }
        }

        return ans;
    }
};