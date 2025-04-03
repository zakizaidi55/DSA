class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int>leftMaximum(nums.size(), 0);
        vector<int>rightMaximum(nums.size(), 0);

        for(int i=1; i<nums.size(); i++) {
            leftMaximum[i] = max(leftMaximum[i-1], nums[i-1]);
        }

        for(int i=nums.size()-2; i>=0; i--) {
            rightMaximum[i] = max(rightMaximum[i+1], nums[i+1]);
        }

        long long result = INT_MIN;

        for(int i=1; i<nums.size(); i++) {
            long long diff = leftMaximum[i] - nums[i];
            long long product = diff * rightMaximum[i];
            result = max(result, product);
        }

        return result;
    }
};

