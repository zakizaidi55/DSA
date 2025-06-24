class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int>ans;

        for(int j=0; j<n; j++) {
            // j-> to find key
            if(nums[j] == key) {
                int start = max(0, j-k);
                int end = min(j+k, n-1);

                // check overlapping
                if(!ans.empty() && ans.back() >= start) {
                    start = ans.back()+1;
                }

                for(int i=start; i<=end; i++) {
                    ans.push_back(i);
                }
            }
        }

        return ans;
    }
};


