
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m/2, n/2);

        while(layers--) {
            vector<int>nums;
            int top = layers;
            int bottom = m - layers - 1;
            int left = layers;
            int right = n - layers - 1;

            // top row (left to right)
            for(int j=left; j<=right; j++) {
                nums.push_back(grid[top][j]);
            }

            // right columns
            for(int j=top+1; j<=bottom-1; j++) {
                nums.push_back(grid[j][right]);
            }

            // bottom row
            for(int j=right; j>=left; j--) {
                nums.push_back(grid[bottom][j]);
            }

            // left col
            for(int j=bottom-1; j>=top+1; j--) {
                nums.push_back(grid[j][left]);
            }

            int len = nums.size();
            int normalisedLength = k%len;

            rotate(nums.begin(), nums.begin()+normalisedLength, nums.end());
            int idx = 0;

            for(int j=left; j<=right; j++) {
                grid[top][j] = nums[idx++];
            }

            // right columns
            for(int j=top+1; j<=bottom-1; j++) {
                grid[j][right] = nums[idx++];
            }

            // bottom row
            for(int j=right; j>=left; j--) {
                grid[bottom][j] = nums[idx++];
            }

            // left col
            for(int j=bottom-1; j>=top+1; j--) {
                grid[j][left] = nums[idx++];
            }
        }

        return grid;
    }
};

