class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> m;
        
        int sum = 0;
        long long int ans = 0;
        long long int windowsum = 0;
        for(int i=0; i<k; i++){
            windowsum += nums[i];
            m[nums[i]]++;
        }

        int i = 0;
        int j = k-1;
        while(j<nums.size()){
            if(m.size() == k){
                ans = max(ans, windowsum);
            }

            m[nums[i]]--; // slide the window
            if(m[nums[i]] == 0){
                // catch-> yha par entry remove karni padegi, to maintain the size of map
                m.erase(nums[i]);
            }
            windowsum -= nums[i];
            i++;

            j++; // Move the right pointer
            if (j < nums.size()) {
                windowsum += nums[j]; // Add the new rightmost element to the sum
                m[nums[j]]++; // Update its frequency
            }
        }
        return ans;
    }
};