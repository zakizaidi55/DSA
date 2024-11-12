class Solution {
public:
    int binarySearch(vector<vector<int>>& items, int queryPrice) {
        int left = 0;
        int right = items.size()-1;

        int maxi = 0;

        while(left <= right) {
            int mid = left + (right - left)/2;
            if(items[mid][0] > queryPrice) {
                // ignore right side
                right = mid-1;
            }

            else {
                // store and move forward
                maxi = max(maxi, items[mid][1]);
                left = mid+1;
            }
        }

        return maxi;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();

        vector<int>result;

        // step1: sort based on price
        sort(items.begin(), items.end());

        // step2: store maxSeen sofar
        int maxSeen = items[0][1];

        for(int i=1; i<items.size(); i++) {
            maxSeen = max(maxSeen, items[i][1]);
            items[i][1] = maxSeen; 
        }

        // step:3: binary search
        for(int i=0; i<queries.size(); i++) {
            int queryPrice = queries[i];
            int ans = binarySearch(items, queryPrice);
            result.push_back(ans);
        }

        return result;
    }
};