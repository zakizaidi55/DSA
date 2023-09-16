class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int index=0; index<n; index++) {
            sum += nums[index];
        }

        int totalSum = (n*(n+1))/2;
        int ans = totalSum - sum;
        return ans;
    }
};


// -----------------------------Method2-----------------------------------
class Solution {
public:
    int missingElementByXOR(vector<int>& nums) {
      int ans = 0;
      // step1: XOR all the values of array
      for(int i=0; i<nums.size(); i++) {
        ans ^= nums[i];
      }

      // Step2: Xor all the values from 0 to n
      for(int i=0; i<=nums.size(); i++) {
        ans ^= i;
      }
      return ans;
    }
    int missingNumber(vector<int>& nums) {
        return missingElementByXOR(nums);
    }
};