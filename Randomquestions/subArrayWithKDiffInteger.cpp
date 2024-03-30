class Solution {
public:
    int atMost(vector<int>&nums, int k) {
        int i = 0;
        int j = 0;
        int count = 0;
        unordered_map<int, int>mp;

        while(i < nums.size() ){
            mp[nums[i]]++;

            while(mp.size() > k) {
                auto it = mp.find(nums[j]);
                it->second--;
                // catch-> yaha fas gya tha
                if(it->second == 0) {
                    mp.erase(it);
                }

                j++;

            }

            count += j-i+1;
            i++;
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return abs(atMost(nums, k) - atMost(nums, k-1));
    }
};