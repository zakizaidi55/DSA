class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long maxElement = *max_element(nums.begin(), nums.end());
        unordered_map<long long, int> mp;
        long long ans = 0;
        int i = 0;
        int j = 0;

        while(j < nums.size()) {
            mp[nums[j]]++;

            while(mp[maxElement] >= k) {
                ans += nums.size()-j;
                mp[nums[i]]--;
                i++;
            }

            j++;
        }

        return ans;
    }
};
