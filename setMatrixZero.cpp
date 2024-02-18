class Solution {
public:
    void setzerorow(vector<vector<int>>& matrix, int i, int n){
        for(int k=0; k<n; k++){
            matrix[i][k] = 0;
        }
    }
    void setzerocol(vector<vector<int>>& matrix, int j, int m){
        for(int k=0; k<m; k++){
            matrix[k][j] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int> >zeroIndex;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                // cout << "matrix  " << matrix[i][j] << endl;
                if(matrix[i][j] == 0) {
                    // cout << i << " " << j << endl;
                    zeroIndex.push_back({i, j});
                }
            }
        }

        for(auto i: zeroIndex) {
            int temp1=i.first;
            int temp2=i.second;

            setzerorow(matrix, temp1, matrix[0].size());
            setzerocol(matrix, temp2, matrix.size());
        }


    }
};