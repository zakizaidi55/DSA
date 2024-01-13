#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(int capacity, int wt[], int profit[], int index, int n) {
    // base case
    // if(index == n-1) {
    //     if(wt[index] <= capacity) {
    //         return profit[index];
    //     }

    //     else {
    //         return 0;
    //     }
    // }

    if(index >= n) {
        return 0;
    }
    int include = 0;
    // inclusion / exclusion
    if(wt[index] <= capacity) {
        include = profit[index] + solveUsingRecursion(capacity-wt[index], wt, profit, index+1, n);
    }

    int exclude = 0 + solveUsingRecursion(capacity, wt, profit, index+1, n);

    int ans = max(include, exclude);

    return ans;

}




int solveUsingMem(int capacity, int wt[], int profit[], int index, int n, vector<vector<int> >&dp) {
    // base case
    // if(index == n-1) {
    //     if(wt[index] <= capacity) {
    //         return profit[index];
    //     }

    //     else {
    //         return 0;
    //     }
    // }

    if(index >= n) {
        return 0;
    }

    // already exist case
    if(dp[capacity][index] != -1) {
        return dp[capacity][index];
    } 
    int include = 0;
    // inclusion / exclusion
    if(wt[index] <= capacity) {
        include = profit[index] + solveUsingMem(capacity-wt[index], wt, profit, index+1, n, dp);
    }

    int exclude = 0 + solveUsingMem(capacity, wt, profit, index+1, n, dp);

    dp[capacity][index] = max(include, exclude);
    return dp[capacity][index];

}


int solveUsingTabulation(int capacity, int wt[], int profit[], int n) {
    vector<vector<int> >dp(capacity+1, vector<int>(n+1, 0));

    for(int row=0; row<capacity; row++) {
        dp[row][n] = 0;
    }

    for(int i=0; i<=capacity; i++) {
        for(int j=n-1; j>=0; j--) {
            int include = 0;
            // inclusion / exclusion
            // cout <<"i " << i << " wt[j]" << wt[j] << endl;
            if(wt[j] <= i) {
                // cout << "wt[j]" << wt[j] << endl;
                include = profit[j] + dp[i-wt[j]][j+1];
                cout <<" include ans " << include << endl;
            }

            int exclude = 0 + dp[i][j+1];
            cout <<" exclude ans " << exclude << endl;

            dp[i][j] = max(include, exclude);
        }
    }

    // for(int i=0; i<dp.size(); i++) {
    //     for(int j=0; j<dp[i].size(); j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[capacity][0];
}


int solveUsingTabulationSO(int capacity, int wt[], int profit[], int n) {
    vector<int>next(capacity+1, 0);
    vector<int>curr(capacity+1, -1);


    for(int j=n-1; j>=0; j--) {
        for(int i=0; i<=capacity; i++) {
            int include = 0;
            // inclusion / exclusion
            if(wt[j] <= i) {
                include = profit[j] + next[i-wt[j]];
            }

            int exclude = 0 + next[j];
            curr[i] = max(include, exclude);
        }
        // shifting
        next = curr;
    }

    return curr[capacity];
}



int main() {

    int capacity = 6;
    int wt[] = {1,2,3};
    int profit[] = {10, 15, 40};
    int index = 0;
    int n = 3;

    vector<vector<int> >dp(capacity+1, vector<int>(n+1, -1));
    // int ans = solveUsingRecursion(capacity, wt, profit, index, n);
    // int ans = solveUsingMem(capacity, wt, profit, index, n, dp);
    int ans = solveUsingTabulationSO(capacity, wt, profit, n);
    cout << "Ans is " << ans << endl;
    return 0;
}