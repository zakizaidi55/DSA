class Solution {
public:
    vector<vector<int> >merge(vector<vector<int> >&intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int> >result;
        
        result.push_back(intervals[0]);

        for(int i=0; i<intervals.size(); i++) {
            if(intervals[i][0] < result.back()[1]) {
                //merge kar dege kyuki wo overlap karege
                result.back()[0] = min(result.back()[0], intervals[i][0]);
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }

            else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int> >xAxis;
        vector<vector<int> >yAxis;


        for(auto&rect: rectangles) {
            int x1 = rect[0];
            int y1 = rect[1];
            int x2 = rect[2];
            int y2 = rect[3];

            xAxis.push_back({x1, x2});
            yAxis.push_back({y1, y2});
        }

        vector<vector<int>> result1 = merge(xAxis);
        if(result1.size() >= 3)
            return true;

        vector<vector<int>> result2 = merge(yAxis);

        return result2.size() >= 3;
    }
};


