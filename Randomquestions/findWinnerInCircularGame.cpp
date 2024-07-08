class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1; i<=n; i++) {
            q.push(i);
        }

        while(q.size() > 1) {
            // till only one element is not left
            for(int i=1; i<k; i++) {
                int frontElement = q.front();
                q.pop();
                q.push(frontElement);
            }

            q.pop();
        }

        return q.front();
    }
};