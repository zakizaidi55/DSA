class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b) {
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }

        return a[0] < b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), comp);
        int result = 0;
        for(int i=0; i<n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            int maxY = INT_MIN;
            for(int j=i+1; j<n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1]; 

                if(y2 > y1) 
                    continue;
                
                if(y2 > maxY) {
                    result++;
                    maxY = y2;
                }
            }
        }

        return result;

        // Approach 1 -> O(n^3)
        // int n = points.size();
        // int result = 0;

        // for(int i=0; i<n; i++) {
        //     // A point
        //     int x1 = points[i][0];
        //     int y1 = points[i][1];

        //     // Find B
        //     for(int j=0; j<n; j++) {
        //         if(i == j)
        //             continue;
                
        //         int x2 = points[j][0];
        //         int y2 = points[j][1]; 

        //         if(x1 <= x2 && y1 >= y2) {
        //             bool hasPointInside = false;
        //             for(int k=0; k<n; k++) {
        //                 if(i == k || j == k)
        //                     continue;
        //                 int x3 = points[k][0];
        //                 int y3 = points[k][1];
        //                 if(x3 >= x1 && x3 <= x2 && y3 <= y1 && y3 >= y2) {
        //                     hasPointInside = true;
        //                     break;
        //                 }
        //             }

        //             if(!hasPointInside)
        //                 result++;
        //         }
        //     }
        // }

        // return result;
    }
};


