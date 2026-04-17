class Solution {
public:
    int reverse(int&num) {
        int reverseNum = 0;
        while(num > 0) {
            int digit = num%10;
            reverseNum = reverseNum * 10 + digit;
            num = num/10;
        }

        return reverseNum;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int>mp; // to store reverse of each number
        int ans = INT_MAX;

        for(int i=0; i<nums.size(); i++) {
            if(mp.find(nums[i]) != mp.end()) {
                // number found, distance check karege
                ans = min(ans, i-mp[nums[i]]);
            }

            // reverse karke insert kardege
            int reverseNum = reverse(nums[i]);
            mp[reverseNum] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};


