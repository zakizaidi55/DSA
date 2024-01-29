class RecentCounter {
public:
    queue<int>q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        // 1.push
        q.push(t);

        // 2. pop invalid req older, older than t-3000
        while(!q.empty() && q.front() < (t-3000)) {
            q.pop();
        }

        // 3. q has only number of recent calls:r = [t-3000, t] 
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */