class Info {
    public:
        char val;
        int cnt;

        Info(char val, int cnt) {
            this->val = val;
            this->cnt = cnt;
        }
};

class compare {
    public:
        bool operator()(Info a, Info b) {
            return a.cnt < b.cnt;
        }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<Info, vector<Info>, compare> maxHeap;
        if(a > 0) {
            Info temp('a',a);
            maxHeap.push(temp);
        }
        if(b > 0) {
            Info temp('b',b);
            maxHeap.push(temp);
        }
        if(c > 0) {
            Info temp('c',c);
            maxHeap.push(temp);
        }
        string ans = "";
        while(maxHeap.size() > 1) {
            Info first = maxHeap.top();
            maxHeap.pop();

            Info second = maxHeap.top();
            maxHeap.pop();

            if(first.cnt >= 2) {
                ans.push_back(first.val);
                ans.push_back(first.val);
                first.cnt -= 2;

            }

            else {
                ans.push_back(first.val);
                first.cnt--;
            }

            // catch-> second ka count agar first se zyada hoga toh 2 baar dalege otherwise single time
            if(second.cnt >= 2 && second.cnt >= first.cnt) {
                ans.push_back(second.val);
                ans.push_back(second.val);
                second.cnt -= 2;

            }

            else {
                ans.push_back(second.val);
                second.cnt--;
            }

            if(first.cnt > 0) {
                maxHeap.push(first);
            }

            if(second.cnt > 0) {
                maxHeap.push(second);
            }
        }

        if(maxHeap.size() == 1) {
            Info first = maxHeap.top();
            maxHeap.pop();

           if(first.cnt >= 2) {
                ans.push_back(first.val);
                ans.push_back(first.val);
                first.cnt -= 2;

            }

            else {
                ans.push_back(first.val);
                first.cnt--;
            }
        }

        return ans;
    }
};