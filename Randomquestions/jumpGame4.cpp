class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int> >mp;
        vector<bool>vis(n, false);

        for(int i=0; i<n; i++) {
            mp[arr[i]].push_back(i);
        }

        // isme hum index push karege
        queue<int>q;
        q.push(0);
        vis[0] = true;  
        int steps = 0;

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int currIndex = q.front();
                q.pop();

                int left = currIndex - 1;
                int right = currIndex + 1;

                if(currIndex == n-1)
                    return steps;
                

                if(left >= 0 && !vis[left]) {
                    q.push(left);
                    vis[left] = true;
                }

                if(right < n && !vis[right]) {
                    q.push(right);
                    vis[right] = true;
                }

                for(int i: mp[arr[currIndex]]) {
                    q.push(i);
                    vis[i] = true;
                }

                // catch yha galti kari thi
                mp.erase(arr[currIndex]);
            }
            steps++;
        }

        return steps;
    }
};


