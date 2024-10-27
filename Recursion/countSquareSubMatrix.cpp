class Solution {
public:
    int m, n;
    int solve(int i, int j, vector<vector<int>>& matrix,vector<vector<int>>& t) {
        
        if (i >= matrix.size() || j >= matrix[0].size()) 
            return 0;

        if (matrix[i][j] == 0)
            return 0;

        if (t[i][j] != -1)
            return t[i][j];

        // Right
        int right = solve(i, j + 1, matrix, t);
        // Diagonal
        int diagonal = solve(i + 1, j + 1, matrix, t);
        // Below
        int below = solve(i + 1, j, matrix, t);

        return t[i][j] = 1 + min({right, diagonal, below});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int result = 0;
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> t(m, vector<int>(n, -1));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                result += solve(i, j, matrix, t);
            }
        }
        return result;
    }
};