class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp; //rem -> index
        mp[0] = -1;

        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            int key = sum%k;

            if(mp.find(key) != mp.end()) {
                // rem found
                if(i - mp[key] >= 2) {
                    return true;
                }
            }

            else {
                mp[key] = i;
            }
        }

        return false;
    }
};