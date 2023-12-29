//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int calculation(char ch, int a, int b) {
        // cout << "printing a " << a << " printing b " << b << " printing ch " << ch << endl;
        if(ch == '+') {
            int res = a+b;
            return res;
        }
        if(ch == '-') {
            int res = a-b;
            return res;
        }
        if(ch == '*') {
            // cout << "yha par " << endl;
            int res = a*b;
            // cout << "printing res " << res << endl;
            return res;
        }
        if(ch == '/') {
            int res = a/b;
            return res;
        }
        
        return 0;
    }
    
    int evaluatePostfix(string S)
    {
        int a;
        int b;
        int res = 0;
        stack<int>sum;
        for(int i=0; i<S.size(); i++) {
           char ch = S[i];
           
            if(ch >= '0' && ch <= '9') {
               sum.push(ch - '0');
            }
            
            if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                if(!sum.empty()) {
                    a = sum.top();
                    sum.pop();
                    // cout << "printing a " << a << endl;
                }
                
               if(!sum.empty()) {
                   b = sum.top();
                   sum.pop();
                //   cout << "printng b " << b << endl;
    
               }
            //   cout << "printing the char " <<ch << endl;
               
            res = calculation(ch, b ,a);
            //   cout << "printing res " << res << endl;
            sum.push(res);
            }

        }  
        // cout << "yaha par " << endl;
        return sum.top();
    }

    
   
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends