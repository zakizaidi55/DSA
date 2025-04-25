class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();

        unordered_map<int, long long> mp; 
        long long sum = 0; 

        long long result = 0;

        mp[0] = 1;
        for(int i=0; i<n; i++) {
            if(nums[i]%modulo == k)
                sum += 1;

            int r1 = sum%modulo;

            int r2 = (r1 - k + modulo)%modulo;

            result += mp[r2];
            mp[r1]++;
        }

        return result;
    }
};


