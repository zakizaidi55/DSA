class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>curr;
        unordered_set<int>prev;
        unordered_set<int>result;

        for(int i=0; i<arr.size(); i++) {
            for(int x: prev) {
                curr.insert(x|arr[i]);
                result.insert(x|arr[i]);
            }
            curr.insert(arr[i]);
            result.insert(arr[i]);
            // saari values prev k andar shift kardi agli iteration k liye
            prev = curr;
            // current ko clear kar diya agli iteration k liye
            curr.clear();
        }

        return result.size();
    }
};


