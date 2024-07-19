class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>rowMin;
        for(int i=0; i<matrix.size(); i++) {
            int rMin = INT_MAX;
            for(int j=0; j<matrix[0].size(); j++) {
                rMin = min(rMin, matrix[i][j]);
            }
            rowMin.push_back(rMin);
        }

        vector<int>colMax;
        for(int i=0; i<matrix[0].size(); i++) { //col wise
            int cMax = INT_MIN;
            for(int j=0; j<matrix.size(); j++) { // row wise
                cMax = max(cMax, matrix[j][i]);
            }
            colMax.push_back(cMax);
        }

        vector<int>ans;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[i].size(); j++) {
                if(matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j])
                    ans.push_back(matrix[i][j]);
            }
        }

        return ans;

    }
};