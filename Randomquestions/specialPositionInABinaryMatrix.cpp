class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int result = 0;
        vector<int>rowCount(m, 0);
        vector<int>colCount(n, 0);

        for(int row=0; row<m; row++) {
            for(int col=0; col<n; col++) {
                if(mat[row][col] == 1) {
                    rowCount[row]++;
                    colCount[col]++;
                }
            }
        }

        for(int row=0; row<m; row++) {
            for(int col=0; col<n; col++) {
                if(mat[row][col] == 1) {
                    if(rowCount[row] == 1 && colCount[col] == 1) {
                        result++;
                    }
                }
            }
        }

        return result;

        // int result = 0;
        // int totalRows = mat.size();
        // int totalCols = mat[0].size();
        // for(int row=0; row<totalRows; row++) {
        //     for(int col=0; col<totalCols; col++) {
        //         if(mat[row][col] == 0) 
        //             continue;
                
        //         bool isGood = true;
        //         // check current row agr koi or 1 milta h toh break kar dege
        //         for(int r=0; r<totalRows; r++) {
        //             if(r != row && mat[r][col] == 1) {
        //                 isGood = false;
        //                 break;   
        //             }   
        //         }

        //         // check current column
        //         for(int c=0; c<totalCols; c++) {
        //             if(c != col && mat[row][c] == 1) {
        //                 isGood = false;
        //                 break;
        //             }
        //         }

        //         if(isGood) 
        //             result++;
        //     }

        // }

        // return result;
    }
};


