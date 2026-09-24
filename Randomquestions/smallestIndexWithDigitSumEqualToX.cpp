class Solution {
public:
    bool isValid(int num, int index) {
        int sum = 0;
        if(num < 10 && num == index)
            return true;
        
        while(num > 0) {
            sum += num%10;
            num = num/10;
        }

        return sum == index;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            if(isValid(nums[i], i))
                return i;
        }

        return -1;
    }
};


