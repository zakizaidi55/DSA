int dx[]{1,-1,0, 0};       
int dy[]{0, 0,1,-1,};
class Solution {
    int n, m;
    vector<vector<char>> b;
    string _word;
    public:
    bool isValid(int i, int j) {
        if(i < 0 || i >= n) {
            return false;
        }

        if(j < 0 || j >= m) {
            return false;
        }

        return true;
    }

    bool dfs(int i, int j , int start) {
        if(start >= _word.size()) {
            return true;
        }

        if(!isValid(i, j) || b[i][j] == '0' || b[i][j] != _word[start]) {
            return false;
        }

        char temp = b[i][j];
        b[i][j] = '0';

        for(int k=0; k<4; k++) {
            if(dfs(i + dx[k], j + dy[k], start+1)) 
                return true;
            
        }

        b[i][j] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        b = board;
        _word = word;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dfs(i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};