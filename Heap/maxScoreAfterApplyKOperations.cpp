class Solution {
public:
    
    
    
    
    long long maxKelements(vector<int>& nums, int k) {

        priority_queue<long long>pq;

        for(auto num: nums) {
            pq.push(num);
        }

        long long ans = 0;

        while(k-- ) {
            long long maxEle = pq.top();
            pq.pop();

            ans += maxEle;
            maxEle = ceil(maxEle/3.0);

            pq.push(maxEle);
        }

        return ans;

        //     long long ans = 0;
        //     while(k--) {
        //         sort(nums.begin(), nums.end());
        //         long long number = nums[nums.size()-1];
        //         ans += number;

        //         number = ceil(number/3.0);
        //         //cout << " number " << number << endl;
        //         nums[nums.size()-1] = number;

        //     }

        //     return ans;
    }
};