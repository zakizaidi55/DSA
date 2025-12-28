class Solution {
public:
    int countNegative(vector<vector<int>>& grid, int currentRow, int start, int end) {
        int count = 0;
        int negativeIndex = -1;
        int totalCols = end+1;
        
        while(start <= end) {
            int mid = (start + end)/2;
            cout << "mid " << mid << endl;
            if(grid[currentRow][mid] < 0) {
                negativeIndex = mid;
                cout << "found negative " << endl;
                end = mid-1;
            }

            else {
                start = mid+1;
            }
        }

        if(negativeIndex != -1) {
            count += totalCols - negativeIndex;
            cout << "count " << count << endl;
        }
        return count;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;

        for(int i=0; i<grid.size(); i++) {
            count += countNegative(grid, i, 0, grid[i].size()-1);
        }

        return count;
    }
};


