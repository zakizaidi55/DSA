class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();

        map<int, vector<int> >mp;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                mp[i+j].push_back(nums[i][j]);
            }
        }

        bool flip = true;
        vector<int>ans;
        for(auto it: mp) {
            if(flip) {
                reverse(it.second.begin(), it.second.end());
            }

            for(int num: it.second)
                ans.push_back(num);
            
            flip = !flip;
        }

        return ans;
    }
};


