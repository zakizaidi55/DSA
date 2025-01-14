class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int>mp; //number->frequency

        int count = 0;
        vector<int>result(A.size(), 0);
        for(int i=0; i<A.size(); i++) {
            int num = A[i];
            mp[num]++;

            if(mp[num] > 1) 
                count++;

            num = B[i];
            mp[num]++;

            if(mp[num] > 1) 
                count++;


            result[i] = count;

        }

        return result;
    }
};