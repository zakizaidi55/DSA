class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        vector<int>storeLastIndex(26, -1);
        vector<int>result;
        for(int i=0; i<s.size(); i++) {
            int index = s[i] - 'a';
            storeLastIndex[index] = i;
        }

        int i = 0;

        while(i < n) {
            int end = storeLastIndex[s[i] - 'a'];

            int j = i;
            while(j < end) {
                //yha par end ko update karna hai, koi or char last m toh nhi hai
                end = max(end, storeLastIndex[s[j] - 'a']);
                j++;
            }

            result.push_back(j-i+1);
            i = j+1;
        }

        return result;
    }
};
