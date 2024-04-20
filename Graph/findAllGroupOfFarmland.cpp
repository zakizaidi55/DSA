class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& land, vector<vector<int>>& v, int& ri, int& rj) {
        v[i][j] = 1; //mark visited in visited array

        // find the neighbouring cell in the right down corner
        if(i + 1 < land.size() && land[i+1][j] == 1 && v[i+1][j] == 0 ) {
            ri = max(ri, i+1);
            dfs(i+1, j, land, v, ri, rj);
        }

        if(j+1 < land[0].size() && land[i][j+1] == 1 && v[i][j+1] == 0) {
            rj = max(rj, j+1);
            dfs(i, j+1, land, v, ri, rj);
        }

    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int> > ans;

        int m = land.size();
        int n = land[0].size();
        vector<vector<int> >v(m, vector<int>(n, 0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++)  {
                if(!v[i][j] && land[i][j] == 1) {
                    int li = i, lj = j, ri = i, rj = j;
                    dfs(i, j, land, v, ri, rj);

                    ans.push_back({li, lj, ri, rj});
                }
            }
        }

        return ans;
    }
};