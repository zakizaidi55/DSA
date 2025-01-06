class Solution {
public:
    vector<int> minOperations(string boxes) {
        int cumVal = 0;
        int cumValSum = 0;
        vector<int>answer(boxes.size(), 0);
        for(int i=0; i<boxes.size(); i++) {
            answer[i] = cumValSum;
            
            cumVal += boxes[i] == '0' ? 0 : 1;
            
            cumValSum += cumVal;
        }

        cumVal = 0;
        cumValSum = 0;

        for(int i=boxes.size()-1; i>=0; i--) {
            answer[i] += cumValSum;

            cumVal += boxes[i] == '1' ? 1 : 0;

            cumValSum += cumVal;
        }

        return answer;

        // -------------------------------Approach 1 O(n^2)-------------------------------

        // unordered_map<int, int>mp; // to store the index where 1 is present
        // vector<int>ans(boxes.size(), 0);

        // for(int i=0; i<boxes.size(); i++) {
        //     if(boxes[i] == '1') {
        //         mp[i] = 1;
        //     }
        // }

        // for(int i=0; i<boxes.size(); i++) {
        //     int num = 0;
        //     for(auto&it: mp) {
        //         //it->first = index
        //         //it->second = 1
        //         num += abs(i - it.first); 
        //     }

        //     ans[i] = num;
        // }

        // return ans;
    }
};