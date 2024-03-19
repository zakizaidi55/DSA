class Solution {
public:
    bool isSafe(int row, int col , char value, vector<vector<char>>& board) {
        // same row me wo number na ho
        // same col me wo number na ho
        // same 3*3 matrix me wo na ho
        int n = board.size();
        // same row
        for(int i=0; i<n; i++) {
            if(board[row][i] == value) {
                return false;
            }
        }

        // col check
        for(int i=0; i<n; i++) {
            if(board[i][col] == value) {
                return false;
            }
        }

        // 3*3 matrix
        for(int i=0; i<n; i++) {
            // yaha par hi galti hoti hai
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == value) {
                return false;
            }
        }

        return true;
    }
    bool solveHelper(vector<vector<char>>& board) {
        int n = board.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                // check empty cell
                if(board[i][j] == '.') {
                    // try to fill from 1 to 9 
                    for(char ch='1'; ch<='9'; ch++) {
                        if(isSafe(i, j, ch, board)) {
                            // place the number
                            board[i][j] = ch;
                            // recursion
                            bool recursionAns = solveHelper(board);
                            if(recursionAns == true) {
                                return true;
                            }

                            else {
                                // recursion ans nhi la paaya
                                // iska matlab jo humne insert kara tha wo galat tha
                                // iska matlab backtrack kardo
                                board[i][j] = '.';
                            }

                        }
                    }

                    return false;

                }

                
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solveHelper(board);
    }
};