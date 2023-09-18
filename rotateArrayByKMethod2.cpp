class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n);

        for(int index=0; index<n; index++) {
            int newIndex = (index+k) % n;
            ans[newIndex] = nums[index];
        }
    
        nums = ans;
    }
};



// -------------------------Method3----------------------
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      k = k % nums.size();
      // reverse [0, n-1];
      reverse(nums.begin(), nums.end());

      // reverse [0,k-1]
      reverse(nums.begin(), nums.begin()+k);

      // reverse[k+1, n-1]
      reverse(nums.begin()+k, nums.end());

    }
};