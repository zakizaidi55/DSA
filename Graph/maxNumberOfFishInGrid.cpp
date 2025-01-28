class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int bfs(int i, int j, vector<vector<int>>& grid, int m, int n) {
        queue<pair<int, int>> q;
        q.push({i, j});
        int fishCount = grid[i][j];
        grid[i][j] = 0;
        
        while(!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();

            for(auto &dir : directions) {
                int newi = dir[0] + i;
                int newj = dir[1] + j;

                if(newi >= 0 && newj >= 0 && newi < m && newj < n && grid[newi][newj] > 0) {
                    q.push({newi, newj});
                    fishCount += grid[newi][newj];
                    grid[newi][newj] = 0;
                }
            }
        }

        return fishCount;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxFish = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)  {
                if(grid[i][j] > 0) { 
                    //water cell found
                    maxFish = max(maxFish, bfs(i, j, grid, m, n));
                }
            }
        }

        return maxFish;
    }
};