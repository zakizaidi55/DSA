class Solution {
public:
    bool isIncreasing(vector<int>&nums, int start, int end) {
        for(int i=start; i<end; i++) {
            if(i+1 < end && nums[i] >= nums[i+1]) {
                return false;
            }
        }

        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int start=0; start+2*k<=n; start++) {
            bool found1 = isIncreasing(nums, start, start+k);
            bool found2 = isIncreasing(nums, start+k, start+2*k);

            if(found1 == true && found2 == true) 
                return true;
        }

        return false;
    }
};


// Approach 2

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int currRun = 1;
        int prevRun = 0;
        for(int i=1; i<n; i++) {
            if(nums[i] > nums[i-1]) {
                currRun++;
            }

            else {
                prevRun = currRun;
                currRun = 1;
            }

            // check kya hum currRun se 2 subarray le sakte h
            if(currRun/2 >= k) 
                return true;
            
            if(min(currRun, prevRun) >= k)
                return true;
            
        }

        return false;
    }
};


