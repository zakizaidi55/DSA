class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();

        vector<int>maxRight(n);

        maxRight[n-1] = n-1;

        for(int i=n-2; i>=0; i--) {
            int rightMaxIndex = maxRight[i+1];
            int rightMaxElement = s[rightMaxIndex];
            maxRight[i] = (s[i] > rightMaxElement) ? i : rightMaxIndex ;
        } 

        for(int i=0; i<n; i++) {
            int rightMaxIndex = maxRight[i];
            int maxRightElement = s[rightMaxIndex];

            if(s[i] < maxRightElement) {
                swap(s[i], s[rightMaxIndex]);
                return stoi(s);
            }
        }

        return num;
    }       
};