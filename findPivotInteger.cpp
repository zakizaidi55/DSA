class Solution {
public:
    int pivotInteger(int n) {
        int start = 1;
        int end = n;

        int sumOfAllElement = (n * ( n + 1 ))/2;

        while(start <= end) {
            int mid = start + (end-start)/2;

            int halfSum = (mid * (mid+1))/2;
            int remainingSum = sumOfAllElement - halfSum + mid;

            if(halfSum == remainingSum) {
                return mid;
            }

            else if(halfSum < remainingSum) {
                start = mid+1;
            }

            else {
               end = mid-1;
            }
        }

        return -1;
    }
};