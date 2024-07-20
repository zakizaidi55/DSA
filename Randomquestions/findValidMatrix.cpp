class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<int>row(rowSum.size());
        vector<int>col(colSum.size());

        vector<vector<int> >ans(rowSum.size(), vector<int>(colSum.size()));

        int i = 0; // rowSum iterator
        int j = 0; // colSum iterator

        while(i < rowSum.size() && j < colSum.size()) {
            ans[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= ans[i][j];
            colSum[j] -= ans[i][j];

            if(rowSum[i] == 0) {
                i++;
            }

            if(colSum[j] == 0) {
                j++;
            }
        }

        return ans;
    }
};