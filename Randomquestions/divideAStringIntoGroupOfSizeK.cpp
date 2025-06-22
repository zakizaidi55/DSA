class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        int i = 0;
        int n = s.length();
        while(i < n) {
            int j = (i + k-1 >= n) ? n-1 : (i+k-1);
            string temp = s.substr(i, j-i+1);
            while(temp.length() < k) {
                temp.push_back(fill);
            } 
            ans.push_back(temp);
            i += k; 
        }

        return ans;
    }
};


