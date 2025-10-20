class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int num = 0;
        for(auto x: operations) {
            if(x == "--X" || x == "X--") {
                num--;
            }

            else if(x == "++X" || x == "X++") {
                num++;
            }
        }

        return num;
    }
};


