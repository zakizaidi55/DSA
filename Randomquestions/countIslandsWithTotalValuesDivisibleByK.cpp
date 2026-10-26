class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    long long dfs(int i, int j, int m, int n, vector<vector<int> >&grid) {
        long long sum = grid[i][j];
        grid[i][j] = 0;

        for(int d=0; d<4; d++) {
            int newX = i + dx[d];
            int newY = j + dy[d];

            if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] > 0) {
                sum += dfs(newX, newY, m, n, grid);
            }
        }

        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] > 0) {
                    long long sum = dfs(i, j, m, n, grid);
                    if(sum % k == 0)
                        count++;
                }
            }
        }
        
        return count;
    }
};


