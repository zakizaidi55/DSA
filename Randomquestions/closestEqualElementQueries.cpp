class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int> >mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        vector<int>ans;
        int n = nums.size();

        for(int i=0; i<queries.size(); i++) {
            vector<int>& temp = mp[nums[queries[i]]];

            if(temp.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            auto pos = lower_bound(temp.begin(), temp.end(), queries[i]);
            int idx = pos - temp.begin();

            int res = INT_MAX;

            // right neighbour
            int right = temp[(idx + 1) % temp.size()];
            int dist = abs(queries[i] - right);
            int circularDist = n - dist;
            res = min(res, min(dist, circularDist));

            // left neighbour
            int left = temp[(idx - 1 + temp.size()) % temp.size()];
            dist = abs(queries[i] - left);
            circularDist = n - dist;
            res = min(res, min(dist, circularDist));

            ans.push_back(res);
        }

        return ans;
    }
};


