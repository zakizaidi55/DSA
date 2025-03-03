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

