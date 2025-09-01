class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int> >maxHeap;
        int n = classes.size();
        for(int i=0; i<n; i++) {
            double currPR = (double)(classes[i][0])/classes[i][1];
            double newPR = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double diff = newPR - currPR;
            maxHeap.push({diff, i});
        }

        while(extraStudents--) {
            auto [diff, index] = maxHeap.top();
            maxHeap.pop();

            classes[index][0]++;
            classes[index][1]++;

            double currPR = (double)(classes[index][0])/classes[index][1];
            double newPR = (double)(classes[index][0]+1)/(classes[index][1]+1);
            diff = newPR - currPR;
            maxHeap.push({diff, index});
        }
        
        double result = 0.0;

        for(int i=0; i<n; i++) {
            result += (double)classes[i][0]/classes[i][1]; 
        }

        return result/n;
    }
};


