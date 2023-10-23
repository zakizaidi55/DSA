class Solution {
public:
    void merge(vector<int>& v, vector<int>& temp, int start, int mid, int end) {
        int i = start; 
        int j = mid+1;
        int k = start;
        while(i <= mid && j <= end) {
            if(v[i] <= v[j])
                temp[k++] = v[i++];
            
            else
                temp[k++] = v[j++];
        } 

        // handle remaining element in case of element remaining

        while(i <= mid){
            temp[k++] = v[i++];
        }
        
        while(j <= end){
            temp[k++] = v[j++];
        }
        
        // lets copy merge data
        while(start <= end) {
            v[start] = temp[start];
            start++;
        }

    }
    void mergeSort(vector<int>& v, vector<int>& temp, int start, int end) {
        if(start >= end) {
            return;
        }

        int mid = (start+end)/2;

        // divide
        mergeSort(v,temp, start, mid);
        mergeSort(v,temp, mid+1, end);

        merge(v, temp,start, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size(), 0);
        int end = nums.size()-1; 
        mergeSort(nums, temp, 0, end);

        return nums;
    }
};