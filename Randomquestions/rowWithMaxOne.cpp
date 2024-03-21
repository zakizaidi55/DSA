class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>ans;
        int n = mat.size();
        int oneCount = INT_MIN;// it store max number of one in the row
        int rowNo = -1; //it store the row number which have maximum one

        for(int row=0; row<n; row++) {
            // count become zero before starting the new row
            int count = 0;
            for(int col=0; col<mat[row].size(); col++) {
                if(mat[row][col] == 1)
                    count++; //increment the count when found one
            }

            // after row completion compare the row count with one count
            if(count > oneCount) {
                oneCount = count;
                rowNo = row;
            }
            
        }
        ans.push_back(rowNo);
        ans.push_back(oneCount);
        
        return ans;
    }
};