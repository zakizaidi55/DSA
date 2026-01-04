class Solution {
public:
    int findSum(int num) {
        int count = 0;
        int sum = 0;
        for(int i=1; i*i<=num; i++) {
            if(num%i == 0) {
                int other = num/i;
                if(other == i) {
                    sum += i;
                    count++;
                }

                else {
                    sum += (other + i);
                    count += 2;
                }
            }
        }
    
        
        return count == 4 ? sum : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for(int num: nums) {
            result += findSum(num);
        }
        
        return result;
    }
};


