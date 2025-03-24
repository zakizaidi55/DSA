class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int daysOff = 0;

        int start = 0;
        int end = 0;
        //int maxEndTime = INT_MIN;
        sort(meetings.begin(), meetings.end());

        for(int i=0; i<meetings.size(); i++) {
            if(meetings[i][0] > end ) {
                daysOff += meetings[i][0] - end - 1;
            }

            end = max(meetings[i][1], end);
            //maxEndTime = max(maxEndTime, end);
        }
        //catch-> yha par galti kari thi
        if(days > end)
            daysOff += days - end;

        return daysOff;
    }
};


