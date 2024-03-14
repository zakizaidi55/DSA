class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            int sum = nums[i];
            if(sum == goal) 
                ans++;
            
            for(int j=i+1; j<nums.size(); j++) {
                sum += nums[j];
                if(sum == goal)
                    ans++;
                
                else if(sum > goal)
                    break;
            }
        }

        return ans;
    }
};

// =====================================================Using Map==============================================
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int>mp;
        int ans = 0;
        int prefixSum[nums.size()];

        prefixSum[0] = nums[0];

        for(int i=1; i<nums.size(); i++) {
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }

        for(int i=0; i<nums.size(); i++) {
            if(prefixSum[i] == goal) {
                ans++;
            }

            if(mp.find(prefixSum[i] - goal) != mp.end()) {
                ans += mp[prefixSum[i]-goal];
            }

            mp[prefixSum[i]]++;
        }

        return ans;
    }
};