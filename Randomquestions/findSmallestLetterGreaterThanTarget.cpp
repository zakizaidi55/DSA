class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0;
        int end = letters.size()-1;
        char ans = '0';
        while(start <= end) {
            int mid = (start + end)/2;
            if(letters[mid] > target) {
                ans = letters[mid];
                end = mid-1;
            }

            else {
                start = mid+1;
            }
        }

        return ans == '0' ? letters[0] : ans;
    }
};

