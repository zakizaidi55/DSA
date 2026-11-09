class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int>availableServer;
        for(int i=0; i<k; i++) {
            availableServer.insert(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > >busyServer;
        vector<int>count(k, 0);

        for(int i=0; i<arrival.size(); i++) {
            int time = arrival[i];
            // mujhe apne busy server me se wo sab server nikalne h jo free ho gye ho or unko wapas available m dalna h
            while(!busyServer.empty() && busyServer.top().first <= time) {
                int server = busyServer.top().second;
                busyServer.pop();
                availableServer.insert(server);
            }

            // targetted server find karna hai
            int target = i % k;
            auto it = availableServer.lower_bound(target);
            // yeh condition h wrap around ki
            if(it == availableServer.end()) 
                it = availableServer.begin();

            // agr mujhe koi server nhi milta h toh req drop kar dege
            if(availableServer.empty()) 
                continue;
            
            int targetServer = *it;
            availableServer.erase(it);
            busyServer.push({time + load[i], targetServer});
            count[targetServer]++;
        }

        int maxNumberOfReq = *max_element(count.begin(), count.end());
        vector<int>result;

        for(int i=0; i<k; i++) {
            if(count[i] == maxNumberOfReq) 
                result.push_back(i);
        }

        return result;
    }
};


