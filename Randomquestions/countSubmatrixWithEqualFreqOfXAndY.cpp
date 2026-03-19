class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int> >cummSumX(m, vector<int>(n, 0));
        vector<vector<int> >cummSumY(m, vector<int>(n, 0));
        int count = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                cummSumX[i][j] = (grid[i][j] == 'X');
                cummSumY[i][j] = (grid[i][j] == 'Y');

                if(i-1 >= 0) {
                    cummSumX[i][j] += cummSumX[i-1][j];
                    cummSumY[i][j] += cummSumY[i-1][j];
                }

                if(j-1 >= 0) {
                    cummSumX[i][j] += cummSumX[i][j-1];
                    cummSumY[i][j] += cummSumY[i][j-1];
                }

                if(i-1 >= 0 && j-1 >= 0) {
                    cummSumX[i][j] -= cummSumX[i-1][j-1];
                    cummSumY[i][j] -= cummSumY[i-1][j-1];
                }

                if(cummSumX[i][j] == cummSumY[i][j] && cummSumX[i][j] > 0) {
                    count++;
                }
            }
        }

        return count;
    }
};


