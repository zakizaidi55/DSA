class Solution {
public:
    bool canDistributeHelper(vector<int>& nums, vector<int>& quantity, int customerIndex, vector<int>& count) {
        // base condition
        if(customerIndex == quantity.size())
            return true;


        for(int i=0; i<count.size(); i++) {
            if(count[i] >= quantity[customerIndex]) {
                count[i] -= quantity[customerIndex];

                if(canDistributeHelper(nums, quantity, customerIndex+1, count)) {
                    return true;
                } 

                // backtrack
                count[i] += quantity[customerIndex];
            }
        }

        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> countMap;
        for(auto num: nums) {
            countMap[num]++;
        }

        vector<int>count;
        for(auto it:countMap) {
            count.push_back(it.second);
        }


        // sort in descending orders
        sort(quantity.rbegin(), quantity.rend());


        return canDistributeHelper(nums, quantity, 0, count);
    }
};