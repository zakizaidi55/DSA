class Solution {
public:
    int findTheWinner(int n, int k) {
        // all player should go into queue
        queue<int>q;

        for(int i=1; i<=n; i++) {
            q.push(i);
        }

        while(q.size() > 1) {
            for(int i=1; i<k; i++) {
                int player = q.front();
                q.pop();
                q.push(player);
            }

            // kth element should be eliminated
            q.pop();
        }
    

        return q.front();
    }
};