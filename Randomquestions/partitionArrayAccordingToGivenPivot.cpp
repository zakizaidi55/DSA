class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>smallThenPivot;
        vector<int>samePivot;
        vector<int>largeThenPivot;


        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < pivot)
                smallThenPivot.push_back(nums[i]);
            
            else if(nums[i] == pivot) 
                samePivot.push_back(nums[i]);
            
            else
                largeThenPivot(nums[i]);
        }

        //now put all the elements in original array
        int i = 0;// to traverse on the original array
        int j = 0;

        while(j < smallThenPivot.size()) 
            nums[i++] = smallThenPivot[j++];

        j = 0;
        
        while(j < samePivot.size()) 
            nums[i++] = samePivot[j++];
    
        j = 0;
        
        while(j < largeThenPivot.size()) 
            nums[i++] = largeThenPivot[j++];

        
        return nums;
    }
}

//----------------------------Method 2----------------------------------

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int countLess = 0;
        int countEqual = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < pivot) 
                countLess++;
            
            else if(nums[i] == pivot)
                countEqual++;
        }

        int i = 0; //index of less then pivot;
        int j = countLess; // index of equal element
        int k = countLess + countEqual; // index of large element

        vector<int>ans(nums.size());
        for(int&num: nums ) {
            if(num < pivot)
                ans[i++] = num;
            
            else if(num == pivot)
                ans[j++] = num;
            
            else
                ans[k++] = num;
        }

        return ans;

    }
};
