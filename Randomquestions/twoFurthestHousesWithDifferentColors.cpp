class Solution {
public:
    int maxDistance(vector<int>& colors) {
        // int result = 0;
        // for(int i=0; i<colors.size(); i++) {
        //     for(int j=i+1; j<colors.size(); j++) {
        //         if(colors[i] != colors[j]) {
        //             result = max(result, j-i);
        //         }
        //     }
        // }

        // return result;

        int result = 0;
        int n = colors.size();
        int i = 0;

        while(colors[i] == colors[n-1]) {
            i++;
        }

        result = max(result, abs(n-1 - i));

        i = n-1;
        while(colors[0] == colors[i]) {
            i--;
        }

        result = max(result, i);

        return result;
    }
};
