class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // vector<int>point;

        sort(intervals.begin(), intervals.end());
        // point.push_back(intervals[0][1]); // maintain initial poins
        priority_queue<int, vector<int>, greater<int> >minHeap;
        for(int i=0; i<intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            //catch-> hum ek pair ko ek hi group m rakh sakte hai
            if(!minHeap.empty() && minHeap.top() < start) {
                minHeap.pop();
            }

            minHeap.push(end);
        }

        return minHeap.size();
    }
};