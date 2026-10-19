class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < target) 
                count++;
        }

        // ab mere pass target element se less than elements ka count h
        vector<int>ans;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == target) {
                ans.push_back(count);
                // mujhe aage badhana hoga taaki next index push ho sakte
                count++;
            }
        }

        return ans;

        // sort(nums.begin(), nums.end());
        // vector<int>ans;
        // for(int i=0; i<nums.size(); i++) {
        //     if(nums[i] == target ) 
        //         ans.push_back(i);
        // }

        // return ans;
    }
};


