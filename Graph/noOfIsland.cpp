class Solution {
public:
    void bfs(map< pair<int,int>, bool >& visited, int row, int col, vector<vector<char>>& grid){
        queue<pair<int,int> > q;
        //initial steps
        q.push({row,col});
        visited[{row,col}] = true;

        while(!q.empty()) {
            pair<int,int> fNode = q.front();
            q.pop();
            int x = fNode.first;
            int y = fNode.second;

            //i can move in 4 directions
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0; i<4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if( newX >=0 && newX<grid.size() && newY>=0 && newY<grid[0].size() &&
                    !visited[{newX, newY}] && grid[newX][newY] == '1') {
                    q.push({newX, newY});
                    visited[{newX, newY}] = true;
                }

            } 
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        map< pair<int,int>, bool > visited;
        int count = 0;

        for(int row=0; row<grid.size(); row++) {
            int n = grid[row].size();
            for(int col=0; col<n; col++) {
                if(!visited[{row,col}] && grid[row][col] == '1') {
                    bfs(visited, row, col,grid);
                    count++;
                }
            }
        }
        return count;
    }
};





// ==========================Using BFS===============================
class Solution {
public:
    bool isSafe(int newX, int newY,  vector<vector<char>>& grid, map<pair<int, int>, bool>& vis) {
        if(newX >=0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && grid[newX][newY] == '1' && vis[{newX, newY}] == false) {
            return true;
        }

        else {
            return false;
        }
    }

    void bfs(int srcX, int srcY, vector<vector<char>>& grid, map<pair<int, int>, bool>& vis) {
        queue<pair<int, int> >q;
        // initial state
        q.push({srcX, srcY});
        vis[{srcX, srcY}] = true;

        while(!q.empty()) {
            pair<int, int> frontNodePair = q.front();
            q.pop();
            int tempX = frontNodePair.first;
            int tempY = frontNodePair.second;  
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};

            for(int i=0; i<4; i++) {
                int newX = tempX + dx[i];
                int newY = tempY + dy[i];
                if(isSafe(newX, newY, grid, vis)) {
                    q.push({newX, newY});
                    vis[{newX, newY}] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        map<pair<int, int>, bool> vis;
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[{i, j}] && grid[i][j] == '1') {
                    bfs(i, j, grid, vis);
                    count++;
                }
            }
        }

        return count;
    }
};