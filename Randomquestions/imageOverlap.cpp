class Solution {
public:
    int countOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int rowOffset, int colOffset) {
        int count = 0;
        for(int i=0; i<img1.size(); i++) {
            for(int j=0; j<img2.size(); j++) {
                int img2Row = i + rowOffset;
                int img2Col = j + colOffset;

                if(img2Row < 0 || img2Row >= img2.size() || img2Col < 0 || img2Col >= img2.size())
                    continue;
                
                if(img1[i][j] == 1 && img2[img2Row][img2Col] == 1)
                    count++;
            }
        }

        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxCount = 0;

        for (int rowOffset=-n+1; rowOffset<n; rowOffset++) {
            for(int colOffset=-n+1; colOffset<n; colOffset++) {
                int count = countOverlap(img1, img2, rowOffset, colOffset);
                maxCount = max(count, maxCount);
            }
        }

        return maxCount;
    }
};


