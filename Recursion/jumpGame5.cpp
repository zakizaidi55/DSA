class Solution {
public:
    // int solveUsingRec(vector<int>& arr, int i, int d) {
    //     int result = 1;
    //     int n = arr.size();
    //     for(int j=i-1; j>= max(0, i-d); j--) {
    //         if(arr[j] >= arr[i])
    //             break;

            
    //         result = max(result, 1 + solveUsingRec(arr, j, d));
    //     }

    //     for(int j=i+1; j <= min(n-1, i+d); j++) {
    //         if(arr[j] >= arr[i])
    //             break;
            
    //         result = max(result, 1 + solveUsingRec(arr, j, d));
    //     }

    //     return result;
    // }

    int sovleUsingMem(vector<int>& arr, int i, int d, vector<int>&dp) {
        int result = 1;
        int n = arr.size();

        if(dp[i] != -1)
            return dp[i];

        for(int j=i-1; j>= max(0, i-d); j--) {
            if(arr[j] >= arr[i])
                break;
           
            result = max(result, 1 + sovleUsingMem(arr, j, d, dp));
        }

        for(int j=i+1; j <= min(n-1, i+d); j++) {
            if(arr[j] >= arr[i])
                break;
            
            result = max(result, 1 + sovleUsingMem(arr, j, d, dp));
        }

        return dp[i] = result;
    }

    int maxJumps(vector<int>& arr, int d) {
        int result = 0;
        vector<int>dp(arr.size()+1, -1);
        for(int i=0; i<arr.size(); i++) {
            // result = max(result, solveUsingRec(arr, i, d));
            result = max(result, sovleUsingMem(arr, i, d, dp));
        }

        return result;
    }
};


