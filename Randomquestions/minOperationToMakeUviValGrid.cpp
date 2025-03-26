class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();    
        int m = grid[0].size();
        if(m*n == 1)
            return 0;
        
        
        vector<int>arr(m*n);
        int k = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                arr[k++] = grid[i][j];
            }
        }

        sort(arr.begin(), arr.end());

        int median1 = arr[arr.size()/2];
        int median2 = arr[arr.size()/2 - 1];

        int cost1 = 0;
        int cost2 = 0;

        for(int i=0; i<arr.size(); i++) {
            if((arr[i] - median1) % x != 0)
                return -1;
            

            cost1 += abs(arr[i] - median1) / x;
            cost2 += abs(arr[i] - median2) / x;
        }

        return min(cost1, cost2);
    }
};



