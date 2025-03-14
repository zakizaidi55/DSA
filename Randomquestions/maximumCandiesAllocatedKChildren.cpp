class Solution {
public:
    bool canDistribute(int mid, vector<int>&candies, long long k) {
        long long count = 0;
        for(int i=0; i<candies.size(); i++) {
            count += candies[i]/mid;

            if(count >= k)
                return true;
        }
        return false;
    }


    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int maxElement = 0;
        long long total = 0;
        for(int i = 0; i < n; i++) {
            total += candies[i];
            maxElement = max(maxElement, candies[i]);
        }

        if(total < k)
            return 0;
        
        //now do with binary search
        long long left = 1;
        long long right = maxElement;
        int result = 0;

        while(left <= right) {
            long long mid = left + (right-left)/2;

            if(canDistribute(mid, candies, k)) {
                result = mid;
                left = mid+1;
            }

            else {
                right = mid-1;
            }
        }

        return result;
    }
};

