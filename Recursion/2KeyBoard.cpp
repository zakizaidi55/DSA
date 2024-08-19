class Solution {
public:
    int solveUsingRec(int currA, int clipA, int n) {
        if(currA == n) 
            return 0;
        
        if(currA > n) 
            return 100000;
        
        int copyAllPaste = 1 + 1 + solveUsingRec(currA + currA, currA, n);

        int paste = 1 + solveUsingRec(currA + clipA, clipA, n);

        return min(copyAllPaste, paste);
    }
    int minSteps(int n) {
        if(n == 1)
            return 0;
        
        int currA = 1;
        int clipBoardA = 1;

        return 1 + solveUsingRec(currA, clipBoardA, n);
    }
};