class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int>freq;
        for(int i: nums) {
            freq[i]++;
        }

        int result = 0;
        if((freq[1]&1)) {
            // odd
            result = freq[1];
        }

        else {
            // even
            result = freq[1]-1;
        }

        for(auto it: freq) {
            if(it.first == 1) {
                // skip 1
                continue;
            }

            int len = 0;
            long long curr = it.first;

            while(freq.count(curr) && freq[curr] > 1) {
                len += 2;
                curr = curr * curr;
            }

            if(freq.count(curr) == 1) {
                len += 1;
            }

            else {
                len -= 1;
            }

            result = max(result, len);
        }

        return result;
    }
};


