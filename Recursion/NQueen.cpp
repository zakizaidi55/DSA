class Solution {
public:
    unordered_map<int, bool>rowCheck;
    unordered_map<int, bool>topDiagonal;
    unordered_map<int, bool>bottomDiagonal;

    bool isSafe(int row, int col, vector<vector<char>>& board, vector<vector<string>>& ans) {
        if(rowCheck[row] == true) {
            return false;
        }

        if(topDiagonal[col-row] == true) {
            return false;
        }

        if(bottomDiagonal[row+col] == true) {
            return false;
        }

        return true;
    }

    void storeSolution(vector<vector<char> >board, vector<vector<string> >&ans) {
        vector<string> tempSol;
        for(auto vec: board) {
            string temp = "";
            for(auto ch: vec) {
                temp.push_back(ch);
            }
            tempSol.push_back(temp);
        }

        ans.push_back(tempSol);
    }

    void solve(vector<vector<char> >& board, vector<vector<string> >&ans, int n, int col) {
        // base case
        if(col >= n) {
            // saare col process ho gye h
            // we have a sol
            storeSolution(board, ans);
        }

        // main logic
        // iss col har row par queen place karke dekho
        for(int row=0; row<n; row++) {
            if(isSafe(row, col, board, ans)) {
                // queen place
                board[row][col] = 'Q';
                rowCheck[row] = true;
                topDiagonal[col-row] = true;
                bottomDiagonal[row+col] = true;
                
                solve(board, ans, n, col+1);

                // backtrack
                board[row][col] = '.';
                rowCheck[row] = false;
                topDiagonal[col-row] = false;
                bottomDiagonal[row+col] = false;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> >ans;
        vector<vector<char> >boards(n, vector<char>(n, '.'));
        int col = 0;
        solve(boards, ans, n, col);
        return ans;

    }
};