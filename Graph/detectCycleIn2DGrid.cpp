class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    bool cycleDetectDFS(int r, int c, int prevR, int prevC, vector<vector<char> >&grid, vector<vector<bool> >&visited, int m, int n) {

        if(visited[r][c]) {
            return true;
        }

        visited[r][c] = true;

        for(auto &dir : directions) {
            int new_r = r + dir[0]; 
            int new_c = c + dir[1];

            if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n && grid[new_r][new_c] == grid[r][c]) {
                // hum check karege ki hum wapas se parent par toh nhi ja rahe by indexes dekhege
                if(new_r == prevR && new_c == prevC)
                    continue;
                
                // aage ki call karege
                if(cycleDetectDFS(new_r, new_c, r, c, grid, visited, m, n)) {
                    return true;
                }
            }
        }

        return false;

    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool> >visited(m, vector<bool>(n, false));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!visited[i][j] && cycleDetectDFS(i, j, i, j, grid, visited, m, n)) {
                    return true;
                }
            }
        }

        return false;
    }
};


