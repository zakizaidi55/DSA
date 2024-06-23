class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int, int> >maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >minHeap;


        int i = 0;
        int j = 0;
        int maxLength = 0;

        while(j < nums.size()) {
            maxHeap.push({nums[j], j});
            minHeap.push({nums[j], j});

            while(maxHeap.top().first - minHeap.top().first > limit) {
                i = min(maxHeap.top().second, minHeap.top().second ) + 1;

                while(maxHeap.top().second < i) {
                    maxHeap.pop();
                }
                
                while(minHeap.top().second < i) {
                    minHeap.pop();
                }


            }

            maxLength = max(maxLength, j-i+1);
            j++;
        }

        return maxLength;
    }
};