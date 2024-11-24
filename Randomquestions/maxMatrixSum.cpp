class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int negativeNum = 0;
        int smallestNumber = INT_MAX;

        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j] < 0) {
                    negativeNum++;
                }

                ans += abs(matrix[i][j]);
                smallestNumber = min(smallestNumber, abs(matrix[i][j]));
            }
        }

        if(negativeNum % 2 == 0) {
            // it means we can make every number positive
            return ans;
        }

        else {
            // we need to substract the smallest one 2 times
            ans = ans - 2*abs(smallestNumber);
            return ans;
        }
    }
};