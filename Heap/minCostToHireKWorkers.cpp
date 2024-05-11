class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        double result = DBL_MAX;

        vector<pair<double, int> >workerRatio(n);
        for(int i=0; i<n; i++) {
            workerRatio[i] = make_pair((double)wage[i]/quality[i], quality[i]);
        }

        sort(workerRatio.begin(), workerRatio.end());

        priority_queue<double, vector<double> >pq;

        int sumQuality = 0;
        for(int i=0; i<k; i++) {
            pq.push(workerRatio[i].second);
            sumQuality += workerRatio[i].second;
        }

        double managerRatio = workerRatio[k-1].first;
        result = managerRatio * sumQuality;

        for(int i=k; i<n; i++) {
            managerRatio = workerRatio[i].first;
            pq.push(workerRatio[i].second);
            sumQuality += workerRatio[i].second;
            
            if(pq.size() > k) {
                sumQuality -= pq.top();
                pq.pop();
            }


            result = min(result, sumQuality*managerRatio);
        }

        return result;
    }
};