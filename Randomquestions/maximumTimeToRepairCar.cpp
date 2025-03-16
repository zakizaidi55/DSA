class Solution {
public:
    bool isRepaired(vector<int>& ranks, long long cars, long long mid) {
        long long c = 0; // track kitni car repairs ho gyi is mid m
        for(auto&rank: ranks) {
            //catch yha par galti kari thi
            c += sqrt(mid/rank);
        }

        return c >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long start = 1;
        long long end = (long long)*min_element(ranks.begin(), ranks.end()) * cars * cars;

        long long ans = 0;
        while(start <= end) {
            long long mid = start + (end-start)/2;

            if(isRepaired(ranks, cars, mid)) {
                ans = mid;
                end = mid-1;
            }

            else {
                start = mid+1;
            }
        }

        return ans;
    }
};

