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

    cout << endl << endl;
    return dp[capacity][index];

}



int main() {

    int capacity = 4;
    int wt[] = {4, 5,1};
    int profit[] = {1, 2, 3};
    int index = 0;
    int n = 3;

    vector<vector<int> >dp(capacity+1, vector<int>(n+1, -1));
    // int ans = solveUsingRecursion(capacity, wt, profit, index, n);
    int ans = solveUsingMem(capacity, wt, profit, index, n, dp);
    cout << "Ans is " << ans << endl;
    return 0;
}