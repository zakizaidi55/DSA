class Solution {
public:
    vector<vector<int>>permutationUniqueHelper(vector<int>& nums, vector<vector<int> >& ans, int index) 
    {
        if(index == nums.size()) {
            ans.push_back(nums);
            return ans;
        }

        unordered_map<int, bool> visited;

        for(int j=index; j<nums.size(); j++) {
            
            if(visited.find(nums[j]) != visited.end()) {
                continue;
            }
            visited[nums[j]] = true;
            swap(nums[j], nums[index]);
            permutationUniqueHelper(nums,ans,index+1);
            // backtrack
            swap(nums[j], nums[index]);
        }

        return ans;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       
        vector<vector<int> >ans;
        int index = 0;
        permutationUniqueHelper(nums, ans, index);
        // set<vector<int> >st;
        // for(auto element :ans) {
        //     st.insert(element);
        // }
        // ans.clear();
        // for(auto ele: st){
        //     ans.push_back(ele);
        // }
        return ans;
    }
};