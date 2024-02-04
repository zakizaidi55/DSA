//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int W, int val[], int wt[],  vector<vector<int> >&dp) {
        if(i == 0) {
            return ((int)(W/wt[0])) * val[0];
        }  
        
        if(dp[i][W] != -1) {
            return dp[i][W];
        }
        
        int incl = 0;
        if(wt[i] <= W) {
            incl = val[i] + solve(i, W-wt[i], val, wt, dp);
        }
        
        int excl = 0 + solve(i-1, W, val, wt,dp);
        
        dp[i][W] =  max(incl, excl);
        
        return dp[i][W];
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {   
        vector<vector<int> >dp(N+1, vector<int>(W+1, -1));
        return solve(N-1, W, val, wt, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends