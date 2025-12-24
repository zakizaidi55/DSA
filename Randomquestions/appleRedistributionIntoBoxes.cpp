class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end());
        int totalApple = accumulate(apple.begin(), apple.end(), 0);
        int count = 0;

        for(int i=capacity.size()-1; i>=0; i--) {
            totalApple -= capacity[i];
            count++;

            if(totalApple <= 0) 
                break;
        }

        return count;
    }
};


