//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        
        int ans = 0;
        sort(arr, arr + r + 1);
        
        for(int i=0; i<k; i++) {
           ans = arr[i];
        }
        
        return ans;
    }
};