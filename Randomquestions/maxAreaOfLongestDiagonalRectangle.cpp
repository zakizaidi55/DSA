class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        int maxDiagonal = 0;

        for(int i=0; i<dimensions.size(); i++) {
            int length = dimensions[i][0];
            int width = dimensions[i][1];

            int diagonal = length*length + width*width;
            int area = length*width;
            if(diagonal > maxDiagonal){
                maxArea = area;
                maxDiagonal = diagonal;
            }
            else if(diagonal == maxDiagonal) {
                maxArea = max(area, maxArea);
            }
        }

        return maxArea;
    }
};
:
