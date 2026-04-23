class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long>arr(n, 0);

        unordered_map<int, long long> indexSum; 
        unordered_map<int, long long> indexCount; 

        for(int i=0; i<n; i++) {
            long long freq = indexCount[nums[i]];
            long long sum = indexSum[nums[i]];

            arr[i] += freq*i - sum;

            indexCount[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }

        indexSum.clear();
        indexCount.clear();

        
        for(int i=n-1; i>=0; i--) {
            long long freq = indexCount[nums[i]];
            long long sum = indexSum[nums[i]];

            arr[i] += sum - freq*i;

            indexCount[nums[i]] += 1;
            indexSum[nums[i]] += i;
        }

        return arr;
    }
};

