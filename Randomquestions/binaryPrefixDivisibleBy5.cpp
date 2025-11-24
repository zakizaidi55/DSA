class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool>ans(n);

        int curr = 0;
        for(int i=0; i<n; i++) {
            curr = (curr * 2 + nums[i])%5;
            cout << curr << endl;
            ans[i] = (curr == 0);
        }

        return ans;
    }
};


