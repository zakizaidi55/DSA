class Solution {
public:
    void solveUsingRec(int num, int totalNum, vector<int>&ans) {
        // base case
        if(num > totalNum) {
            return;
        }

        ans.push_back(num);

        for(int append=0; append<=9; append++) {
            int newNum = num * 10 + append;

            solveUsingRec(newNum, totalNum, ans);
        }

    }
    vector<int> lexicalOrder(int n) {
        // rec approach
        vector<int>ans;

        for(int startNum=1; startNum<=9; startNum++) {
            solveUsingRec(startNum, n, ans);
        }


        return ans;


        // vector<string>vec;
        // for(int i=1; i<=n; i++) {
        //     vec.push_back(to_string(i));
        // }

        // sort(vec.begin(), vec.end());

        // vector<int>ans;
        // for(auto v: vec) {
        //     ans.push_back(stoi(v));
        // }

        // return ans;
    }
};