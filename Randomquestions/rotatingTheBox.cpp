class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box.size(); 
        int col = box[0].size();

        vector<vector<char> >result(col, vector<char>(row));

        for(int i=0; i<col; i++) {
            for(int j=0; j<row; j++) {
                result[i][j] = box[j][i];
            }
        }

        // for 90 deg rotation
        for(auto&vec: result) {
            reverse(vec.begin(), vec.end());
        }

        row = result.size();
        col = result[0].size();
        for(int j=0; j<col; j++) {
            for(int i=row-1; i>=0; i--) {
                if(result[i][j] == '.') {
                    int stoneRow = -1;

                    for(int k=i-1; k>=0; k--) {
                        if(result[k][j] == '*') 
                            break;
                        
                        else if(result[k][j] == '#') {
                            stoneRow = k;
                            break;
                        }
                    }
                    
                    if(stoneRow != -1) {
                        result[i][j] = '#';
                        result[stoneRow][j] = '.';
                    }
                }
            }
        }

        return result;
    }
};