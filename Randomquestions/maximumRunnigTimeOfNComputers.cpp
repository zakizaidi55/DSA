class Solution {
public:
    bool isPossible(long long mid, vector<int>& batteries, int n) {
        long long targetMinutes = mid * n;

        long long totalMinutes = 0;
        
        for(int i=0; i<batteries.size(); i++) {
            // catch yha par humko min of mid and batteries[i] lena h, 
            totalMinutes += min(mid, (long long)batteries[i]);

            if(totalMinutes >= targetMinutes) 
                return true;
        }

        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left = *min_element(batteries.begin(), batteries.end());
        long long right;

        long long totalSum = accumulate(batteries.begin(),batteries.end(), 0LL);
        right = totalSum/n;

        long long result = 0;
        while(left <= right) {
            long long mid = left + (right-left)/2;

            if(isPossible(mid, batteries, n)) {
                result = mid;
                left = mid + 1;
            }

            else {
                right = mid-1;
            }
        }

        return result;
    }
};


