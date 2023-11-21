//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // step1: push all the person in stack
        int mightBeCel = -1;
        stack<int>st;
        for(int i=0; i<n; i++) {
            st.push(i);
        }
        
        // step 2 : run discard method, to find might be celebrity
        while(st.size() !=  1) {
            int a = st.top();
            st.pop();
            
            int b = st.top(); 
            st.pop();
            
            // if a knows b
            if(M[a][b]) {
                // it means a is not celebrity might be b
                st.push(b);
            }
            
            else {
                // it means b is not celebrity might be a
                st.push(a);
            }
        }
        
        // step 3 to check the remaining element is a celebrity or not
        if(!st.empty()) {
            mightBeCel = st.top();
            st.pop();
            
            // celebrity should not know anyone
            for(int i=0; i<n; i++) {
                if(M[mightBeCel][i] != 0)
                    return -1;
            }
            
            // everyone should know the calebrity
            for(int i=0; i<n; i++) {
                if(M[i][mightBeCel] == 0 && i != mightBeCel) {
                    return -1;
                }
            }
        
        }
        
        // might be celebrity is actual celeberity
        return mightBeCel;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends