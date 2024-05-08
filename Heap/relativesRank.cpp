class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int> >pq; //(score, index)

        for(int i=0; i<score.size(); i++) {
            pq.push({score[i], i});
        }

        vector<string>ans(score.size());
        int place = 1;

        while(!pq.empty()) {
            int currIndex = pq.top().second;
            pq.pop();
            if(place == 1) {
                ans[currIndex] = "Gold Medal";
            }

            else if(place == 2) {
                ans[currIndex] = "Silver Medal";
            }

            else if(place == 3) {
                ans[currIndex] = "Bronze Medal";
            }

            else{
                ans[currIndex] = to_string(place);
            }
            place++;
        }

        return ans;

    }
};