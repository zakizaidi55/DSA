class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = nums.size() - 1;
        int ans = INT_MIN;
        while(i < j) {
            int pair = nums[i] + nums[j];
            cout << pair << endl;
            ans = max(ans, pair);
            i++;
            j--;
        } 

        return ans;
    }


};