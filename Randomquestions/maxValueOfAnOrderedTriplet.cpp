class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = INT_MIN;

        for(int i=0; i<nums.size(); i++) {
            long long diff = 0;
            for(int j=i+1; j<nums.size(); j++) {
                diff = nums[i] - nums[j];
                for(int k=j+1; k<nums.size(); k++) {
                    long long product = diff * nums[k];
                    ans = max(ans, product);
                }
            }
        }

        return ans < 0 ? 0 : ans;

    }
};


