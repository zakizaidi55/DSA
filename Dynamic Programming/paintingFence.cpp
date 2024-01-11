#include <iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(int n, int k) {
  // base case
  if(n == 1) {
    return k;
  }

  if(n == 2) {
    return (k + k * (k-1));
  }

  int ans = (solveUsingRecursion(n-1, k) + solveUsingRecursion(n-2, k)) * (k-1);
  return ans;
}

int solveUsingMem(int n, int k, vector<int>&dp) {
    if(n == 1) {
        return k;
    }

    if(n == 2) {
        return (k + k * (k-1));
    }

    // step3: if answer exist then return the answer
    if(dp[n] != -1) {
        return dp[n];
    }

    // step2: store the ans
    dp[n] = (solveUsingMem(n-1, k, dp) + solveUsingMem(n-2, k,dp)) * (k-1);
    return dp[n];
}


int solveUsingTabulation(int n, int k) {
    vector<int>dp(n+1, 0);

    dp[1] = k;
    dp[2] = k + k * (k-1);

    for(int i=3; i<=n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) * (k-1);
    }

    return dp[n];
}

int solveUsingTabulationSpaceOptimisation(int n, int k) {

    int prev2 = k;
    int prev1 = k + k * (k-1);

    
    if(n == 1) {
        return k;
    } 

    if(n == 2) {
        return( k + k * (k-1));
    }
    int curr;
    for(int i=3; i<=n; i++) {
        curr = prev1 + prev2 * (k-1);
        // important step
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main() {
  int n = 3;
  int k = 2;
//   step1: create a dp Array
    vector<int>dp(n+1, -1);
//   int ans = solveUsingRecursion(n, k);
    // int ans = solveUsingMem(n, k, dp);
    // int ans = solveUsingTabulation(n, k);
    int ans = solveUsingTabulationSpaceOptimisation(n, k);
  cout << "ANS " << ans << endl;
  return 0;
}