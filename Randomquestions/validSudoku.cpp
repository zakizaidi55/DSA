class Solution {
public:
    bool check(vector<vector<char>>& grid, int startRow, int endRow, int startCol, int endCol) {
        unordered_set<char>st; // catch:- isko bhar rakhna h loop se kyuki yha par hum 3*3 matrix check kar rahe h
        for(int row=startRow; row<=endRow; row++) {
            for(int col=startCol; col<=endCol; col++) {
                if(grid[row][col] == '.')
                    continue;
                
                else if(st.find(grid[row][col]) != st.end()) 
                    return false;
                
                else
                    st.insert(grid[row][col]);
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& grid) {
        // check each row
        for(int row=0; row<9; row++) {
            unordered_set<char>st;
            for(int col=0; col<9; col++) {
                if(grid[row][col] == '.')
                    continue;
                
                else if(st.find(grid[row][col]) != st.end()) 
                    return false;
                
                else
                    st.insert(grid[row][col]);
            }
        }
        // check each col
        for(int col=0; col<9; col++) {
            unordered_set<char>st;
            for(int row=0; row<9; row++) {
                if(grid[row][col] == '.')
                    continue;
                
                else if(st.find(grid[row][col]) != st.end()) 
                    return false;
                
                else
                    st.insert(grid[row][col]);
            }
        }

        // check 3*3 
        for(int startRow=0; startRow<9; startRow+=3) {
            int endRow = startRow+2;
            for(int startCol=0; startCol<9; startCol+=3) {
                int endCol = startCol+2;

                bool checkMatrixPartition = check(grid, startRow, endRow, startCol, endCol);
                if(!checkMatrixPartition)
                    return false;
            }
        }

        return true;
    }
};


