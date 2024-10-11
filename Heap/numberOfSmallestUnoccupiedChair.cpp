class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        priority_queue<int, vector<int>, greater<int> >chair;
        priority_queue <pair<int, int>, vector<pair<int, int> >, greater <pair<int, int> > >occupiedChair; //pair-> <departure time, chair>
        int targetFriendTime = times[targetFriend][0];

        sort(times.begin(), times.end());

        for(int i=0; i<times.size(); i++) {
            chair.push(i);
        }

        int startChair = 0; // starting chair number


        for(auto&time: times) {
            int arrivalTime = time[0];
            int departureTime = time[1];

            while(!occupiedChair.empty() && occupiedChair.top().first <= arrivalTime) {
                chair.push(occupiedChair.top().second);
                occupiedChair.pop();
            }

            int chairNum = chair.top();
            chair.pop();
            pair<int, int> chairPair = {departureTime, chairNum};
            occupiedChair.push(chairPair);

            if(arrivalTime == targetFriendTime) {
                return chairPair.second;
                break;
            }

        }

        return 0;

        // vector<int>time(times.size(), -1);
        // int targetFriendTime = times[targetFriend][0];
        // sort(times.begin(), times.end());
        
        // for(auto&t: times) {
        //     int arrivalTime = t[0];
        //     int departureTime = t[1];

        //     for(int i=0; i<times.size(); i++) {
        //         if(time[i] <= arrivalTime) {
        //             time[i] = departureTime;


        //             if(arrivalTime == targetFriendTime) {
        //                 return i;
        //             }

        //             break;
        //         }
        //     }
        // }

        // return 0;
    }
};