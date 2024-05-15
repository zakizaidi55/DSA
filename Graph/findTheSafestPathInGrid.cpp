class Solution {
public:
    int n;
    vector<vector<int> >directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1} };

    // step3: boolean check
    bool check(vector<vector<int> >&distNearestThief, int sf) {
        queue<pair<int, int> >q;

        vector<vector<bool> >visited(n, vector<bool>(n, false));

        

        q.push({0, 0});
        visited[0][0] = true;

        if(distNearestThief[0][0] < sf) {
            return false;
        }

        while(!q.empty()) {
            int currX = q.front().first;
            int currY = q.front().second;

            q.pop();

            if(currX == n-1 && currY == n-1) {
                return true;
            }

            for(vector<int>&dir: directions) {
                int newX = currX + dir[0];
                int newY = currY + dir[1];

                if(newX >= 0 && newX < n && newY >= 0 && newY < n && visited[newX][newY] == false) {
                    if(distNearestThief[newX][newY] < sf) {
                        continue; //reject this cell
                    }

                    q.push({newX, newY});
                    visited[newX][newY] = true;
                }
            }
        }

        return false;
         
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        // step1: precalculation of distNearestTheif - for each cell
        vector<vector<int> >distNearestThief(n, vector<int>(n, -1));
        queue<pair<int, int> >q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int result = 0;

        // push all cells in queue where theives are present
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    q.push(make_pair(i, j));
                    visited[i][j] = true; 
                }
            }
        }

        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int currI = q.front().first;
                int currJ = q.front().second;
                q.pop();
                distNearestThief[currI][currJ] = level;
                
                for(vector<int>&dir: directions) {
                    int newX = currI + dir[0];
                    int newY = currJ + dir[1];

                    if(newX < 0 || newX >= n || newY < 0 || newY >= n || visited[newX][newY]) {
                        continue;
                    }

                    q.push(make_pair(newX, newY));
                    visited[newX][newY] = true;
                }
            }

            level++;
        }

        // step2: apply binary search on Safe factor
        int l = 0;
        int r = 400;

        while(l <= r) {
            int mid_SF = l + (r-l)/2;

            if(check(distNearestThief, mid_SF)) {
                result = mid_SF;
                l = mid_SF+1;

            }

            else {
                r = mid_SF-1;
            }
        }
        return result;
    }
};