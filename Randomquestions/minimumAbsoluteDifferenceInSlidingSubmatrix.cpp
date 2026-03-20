class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> >ans(m-k+1, vector<int>(n-k+1, 0));

        for(int i=0; i<=m-k; i++) {
            for(int j=0; j<=n-k; j++) {
                vector<int>temp;
                for(int r=i; r<i+k; r++) {
                    for(int c=j; c<j+k; c++) {
                        temp.push_back(grid[r][c]);
                    }
                }
                sort(temp.begin(), temp.end());
                int mini = INT_MAX;
                for (int t=1; t<temp.size(); t++) {
                    if(temp[t] != temp[t-1])
                        mini = min(mini, temp[t] - temp[t-1]);
                }

                ans[i][j] = (mini == INT_MAX ? 0 : mini);
            }
        }

        return ans;
    }

};


