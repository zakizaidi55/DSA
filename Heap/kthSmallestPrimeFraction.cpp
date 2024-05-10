class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> minHeap;
        vector<int>ans;

        for(int i=0; i<arr.size()-1; i++) {
            for(int j=i+1; j<arr.size(); j++) {
                minHeap.push({((double) arr[i] / arr[j]), {arr[i], arr[j]}});;

            }
        }

        int i = 0;
        while(i < k-1 ) {
            minHeap.pop();
            i++;
        }

        auto top = minHeap.top();

        ans.push_back(top.second.first);
        ans.push_back(top.second.second);

        return ans;
    }
};