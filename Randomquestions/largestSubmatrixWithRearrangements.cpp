class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxArea = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 1 && i > 0) {
                    matrix[i][j] += matrix[i-1][j];
                }
            }

            vector<int>heights = matrix[i];
            sort(heights.begin(), heights.end(), greater<int>());

            // traverse karege height wale array par or maxArea ko update karege
            for(int k=0; k<n; k++) {
                int base = k+1;
                int height = heights[k];

                maxArea = max(maxArea, base*height);
            }
        }

        return maxArea;
    }
};


