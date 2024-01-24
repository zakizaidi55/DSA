class Solution {
public:
    #define ll long long
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;

        vector<ll> prefix(nums.size(), -1);
        vector<ll> suffix(nums.size(), -1);

        // prefix store the sum of first n element from left to right
        // suffix store the sum of first n element from right to left

        ll sum = 0; // min n element sum
        priority_queue<ll>pq;

        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            pq.push(nums[i]);

            // pop out maximum element
            if(pq.size() > n) {
                sum -= pq.top();
                pq.pop();
            }

            if(pq.size() == n) {
                prefix[i] = sum;
            }
        }

        sum = 0; // max n element sum
         
        priority_queue<ll, vector<ll>, greater<ll> >mini;

        for(int i=nums.size()-1; i>=0; i--) {
            sum += nums[i];
            mini.push(nums[i]);

            // pop out maximum element
            if(mini.size() > n) {
                sum -= mini.top();
                mini.pop();
            }

            if(mini.size() == n) {
                suffix[i] = sum;
            }
        }

        ll ans = LONG_LONG_MAX;
        for(int i=n-1; i<2*n; i++) {
            ans = min(ans, prefix[i] - suffix[i+1]);
        }


        return ans;



    }
};