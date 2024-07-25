class Solution {
public:
    void merge(vector<int>& nums,vector<int>&temp, int start, int mid, int end) {
        int i = start;
        int j = mid+1;
        int k = start;
        while(i <= mid && j <= end) {
            if(nums[i] <= nums[j])
                temp[k++] = nums[i++];
            
            else
                temp[k++] = nums[j++];
        } 

        // handle remaining element in case of element remaining

        while(i <= mid){
            temp[k++] = nums[i++];
        }
        
        while(j <= end){
            temp[k++] = nums[j++];
        }
        
        // lets copy merge data
        while(start <= end) {
            nums[start] = temp[start];
            start++;
        }
    }
    void mergeSort(vector<int>& nums,vector<int>&temp, int start, int end) {
        if(start >= end) {
            return;
        }

        int mid = start + (end-start)/2;

        mergeSort(nums, temp, start, mid);
        mergeSort(nums, temp, mid+1, end);

        merge(nums, temp, start, mid, end);
    }
    vector<int> sortArray(vector<int>& nums) {
       vector<int>temp(nums.size(), 0);
       int end = nums.size()-1; 
       mergeSort(nums, temp, 0, end);

       return temp;
    }
};