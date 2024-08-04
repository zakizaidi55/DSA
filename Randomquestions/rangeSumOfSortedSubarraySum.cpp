class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int size = nums.size();
        vector<int>ans;
        int m = 1e9 + 7;
        
        for(int i=0; i<nums.size(); i++) {
            int sum = 0;
            for(int j=i; j<nums.size(); j++) {
                sum += nums[j];
                ans.push_back(sum);
            } 
        }

        sort(ans.begin(), ans.end());
        int result = 0;
        for(int i=left-1; i<right; i++) {
            result = (result + ans[i])%m;
        }

        return result % m;
    }
};