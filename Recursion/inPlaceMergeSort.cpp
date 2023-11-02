class Solution {
public:
    void mergeInplace(vector<int>& v, int start, int mid, int end) {
        int totalLen = end - start + 1;
        int gap = totalLen/2 + totalLen % 2;
        while(gap > 0) {
            int i = start;
            int j = start + gap;

            while(j <= end) {
                if(v[i] > v[j]) {
                    swap(v[i], v[j]);
                }

                i++;
                j++;

            }
            gap = gap <= 1 ? 0 :( gap/2) + (gap%2);
        }
    }
    void mergeSort(vector<int>& v, int start, int end) {
        if(start >= end) {
            return;
        }

        int mid = (start+end)/2;

        // divide
        mergeSort(v, start, mid);
        mergeSort(v, mid+1, end);

        mergeInplace(v,start, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int end = nums.size()-1; 
        mergeSort(nums, 0, end);

        return nums;
    }
};