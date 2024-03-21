class Solution {
public:
    bool canDistributeHelper(vector<int>& counts, vector<int>& quantity, int ithCustomer) {
        //base case
        if(ithCustomer == quantity.size()) {
            return true;
        }

        for(int i=0; i<counts.size(); i++) {
          if(counts[i] >= quantity[ithCustomer]) {
              counts[i] -= quantity[ithCustomer];

                if(canDistributeHelper(counts, quantity, ithCustomer+1)) {
                  return true;
                }
            //   backtracking
              counts[i] += quantity[ithCustomer];
          } 
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> countMap;
        for(auto num: nums) {
            countMap[num]++;
        }
        vector<int>counts;
        for(auto it:countMap) {
            counts.push_back(it.second);
            sort(quantity.rbegin(), quantity.rend());
        }

        return canDistributeHelper(counts, quantity, 0);       
    }
};