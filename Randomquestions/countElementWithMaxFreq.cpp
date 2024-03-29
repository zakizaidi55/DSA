class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freqMp;
        int maxFreq = 0;
        for (int num : nums) {
            freqMp[num]++;
            maxFreq = max(maxFreq, freqMp[num]);
        }

        int maxFreqEleCnt = 0;
        for (auto it : freqMp) {
            int currEleFreq = it.second;
            if (currEleFreq == maxFreq) {
                maxFreqEleCnt++;
            }
        }
        return maxFreq * maxFreqEleCnt;
    }
};