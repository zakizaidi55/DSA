class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int k = k1 + k2;

        vector<int>vec(1e5+1, 0);
        for(int i=0; i<nums1.size(); i++) {
            int diff = abs(nums1[i] - nums2[i]);
            vec[diff]++;
        }

        long long ans = 0;
        for(int i=vec.size()-1; i>0 && k > 0; i--) {
            int count = vec[i];
            int countOfOperation = min(k, count);
            vec[i] -= countOfOperation;
            vec[i-1] += countOfOperation;
            k -= countOfOperation;

        }

        for(long long i=1; i<vec.size(); i++) {
            long long diff = (vec[i] * i * i);
            ans += diff;
        }

        return ans;
        // priority_queue<int>pq;

        // for(int i=0; i<nums1.size(); i++) {
        //     int diff = abs(nums1[i] - nums2[i]);
        //     pq.push(diff);
        // }

        // while(k > 0 && pq.top() > 0) {
        //     int largestNumber = pq.top();
        //     pq.pop();
        //     k--;
        //     pq.push(largestNumber-1);
        // }

        // long long ans = 0;
        // while(!pq.empty()) {
        //     long long top = pq.top();
        //     ans += (top*top);
        //     pq.pop();
        // }

        // return ans;
    }
};


