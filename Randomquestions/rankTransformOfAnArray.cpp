class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > >minHeap;

        for(int i=0; i<arr.size(); i++) {
            minHeap.push({arr[i], i});
        }

        int rank = 0;
        int prev = INT_MIN;

        while(!minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();

            int element = top.first;
            int index = top.second;

            if(element > prev) {
                rank++;
            }

            arr[index] = rank;

            // main kaam galti kari thi
            prev = element;
        }

        return arr;

        // map<int, list<int> >mp; //value->index
        
        // for(int i=0; i<arr.size(); i++) {
        //     mp[arr[i]].push_back(i);
        // }
        // int rank = 1;
        // for(auto it: mp) {
        //     for(auto ele: it.second) {
        //         arr[ele] = rank;
        //     }
        //     rank++;
        // }

        // return arr;
    }
};