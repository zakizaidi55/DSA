class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        int maxNum = INT_MIN;
        for (auto it : freq) {
            int number = it.first;
            int frequency = it.second;
            if(frequency == number) {
                maxNum = max(maxNum, number);
            }
        }

        return maxNum == INT_MIN ? -1 : maxNum;
    }
};


