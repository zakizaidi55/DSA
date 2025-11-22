class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        for(int i: nums) {
            if(i%3 != 0)
                operations++;
        }

        return operations;
    }
};

