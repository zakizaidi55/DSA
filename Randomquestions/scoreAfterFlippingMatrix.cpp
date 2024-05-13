class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0; i<m; i++) {
            if(grid[i][0] == 0) {
                // flip that row
                for(int j=0; j<n; j++) {
                    grid[i][j] = 1 - grid[i][j]; 
                }
            }
        }


        for(int j=0; j<n; j++) {
            int zeroCount = 0;  // count the no of zero in a col
            for(int i=0; i<m; i++) {
                if(grid[i][j] == 0) {
                    zeroCount++;
                }
            }

            int oneCount = m - zeroCount;

            if(zeroCount > oneCount) {
                for(int i=0; i<m; i++) {
                    grid[i][j] = 1 - grid[i][j];  
                }
            }
        }

        int score = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int value = grid[i][j] * pow(2, n-j-1);
                score += value;
            }
        }

        return score;
    }
};