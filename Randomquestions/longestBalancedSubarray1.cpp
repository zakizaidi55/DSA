class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            unordered_set<int>evenCount;
            unordered_set<int>oddCount;
            for(int j=i; j<nums.size(); j++) {
                if(nums[j]%2 == 0) {
                    // even number
                    evenCount.insert(nums[j]);
                }

                else {
                    // odd
                    oddCount.insert(nums[j]);
                }

                if(evenCount.size() == oddCount.size()) {
                    ans = max(ans, j-i+1);
                }
            }
        }

        return ans;
    }
};
