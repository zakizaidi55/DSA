class Solution {
public:
    int minIndex(vector<int>&nums) {
        int index = -1;
        int sum = INT_MAX;
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] + nums[i+1] < sum) {
                index = i;
                sum = nums[i] + nums[i+1];
            }
        }

        return index;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;
        while(!is_sorted(nums.begin(), nums.end())) {
            int index = minIndex(nums);
            cout << "index " << index << endl;
            if(index != -1) {
                nums[index] = nums[index] + nums[index+1];
                nums.erase(nums.begin()+index+1);
                operations++;
            }
        }

        return operations;
    }
};


