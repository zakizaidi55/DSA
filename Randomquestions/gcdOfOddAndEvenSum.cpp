class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // Sum of first n odd numbers  = n * n
        // Sum of first n even numbers = n * (n + 1)

        int oddCount = n * n;
        int evenCount = n * (n+1);

        if(oddCount == 0) 
            return evenCount;
        
        if(evenCount == 0)
            return oddCount;
        
        while(oddCount > 0 && evenCount > 0) {
            if(oddCount > evenCount) 
                oddCount = oddCount - evenCount;
            
            else 
                evenCount = evenCount - oddCount;
        }

        return oddCount == 0 ? evenCount : oddCount;
    }
};
