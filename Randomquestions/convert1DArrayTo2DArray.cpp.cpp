class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if((m*n) < original.size() || original.size() < (m*n)) {
            return {};
        }

        vector<vector<int> >matrix(m, vector<int>(n, 0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                matrix[i][j] = original[n * i + j];
            }
        }

        return matrix;
    }
};