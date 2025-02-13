class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long, vector<long long>, greater<long long> >minHeap;
    
            for(int ele: nums) {
                minHeap.push(ele);
            }
    
            int operation = 0;
            // minheap is ready
            //1,2,3,10,11
    
            // perform the given operations
            while(minHeap.size() > 1 && minHeap.top() < k) {
                long long top1 = minHeap.top();
                minHeap.pop();
    
                long long top2 = minHeap.top();
                minHeap.pop();
    
                long long mini = min(top1, top2);
                long long maxi = max(top1, top2);
    
                long long nextToPush = mini * 2 + maxi;
                minHeap.push(nextToPush);
                operation++;
            }
    
            return operation;
        }
    };