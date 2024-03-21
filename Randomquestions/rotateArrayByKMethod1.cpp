class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int lastIndex = nums.size() - 1; 
        int firstIndex = nums[0];
        vector<int>temp;
        
        if(nums.size() >= k ) {
        for(int i=lastIndex-k+1; i<nums.size(); i++) {
            temp.push_back(nums[i]);
        }

        // for(int i=0; i<temp.size(); i++) {
        //     cout << temp[i];
        // }

        for(int i=nums.size()-1; i>k-1; i--) {
            nums[i] = nums[i-k];
        }
       for(int i=0; i<k; i++) {
           nums[i] = temp[i];
       }
        }

        
    }
};