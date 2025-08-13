class Solution {
public:
    bool solveUsingRec(int n) {
        if(n <= 0)
            return false;
        
        if(n == 1)
            return true;
        
        int rem = n%3;
        if(rem != 0)
            return false;
        
        return solveUsingRec(n/3);
    }
    bool isPowerOfThree(int n) {
        
        return solveUsingRec(n);
        
        // if(n == 0)
        //     return false;
            
        // while(n) {
        //     if(n == 1)
        //         break;
        //     int rem = n%3;
        //     if(rem != 0)
        //         return false;
            
        //     n = n/3;
        // }

        // return true;
    }
};


