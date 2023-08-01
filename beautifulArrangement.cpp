class Solution {
public:
    void countArrangementHelper(vector<int>& v, int& n, int& ans, int currNumber) {
        // base case

        if(currNumber == n+1) {
            ++ans;
            return;
        }

        for(int i=1; i<=n; i++) {
            if(v[i] == 0 && (currNumber % i == 0 || i % currNumber == 0)) {
                v[i] = currNumber;
                countArrangementHelper(v, n, ans, currNumber+1);
                v[i] = 0; //backtrack
                
            }
        }
    }

    int countArrangement(int n) {
        vector<int>v(n+1);
        int ans = 0;
        countArrangementHelper(v, n, ans, 1);
        return ans;
    }
};