class Solution {
public:
    int oneDArrayCount(vector<int>&vec) {
        int count = 0;
        int res = 0;

        for(int i=0; i<vec.size(); i++) {
            if(vec[i] == 0)
                count = 0;
            
            else {
                count++;
            }

            res += count;
        }
        return res;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int result = 0;
        for(int startRow=0; startRow<m; startRow++) {
            vector<int>vec(n, 1);
            for(int endRow=startRow; endRow<m; endRow++) {
                for(int col=0; col<n; col++) {
                    vec[col] = vec[col]&mat[endRow][col];
                }

                result += oneDArrayCount(vec);
            }
        }

        return result;
    }
};


