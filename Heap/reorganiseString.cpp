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
        bool operator() (Info a, Info b ) {
            return a.cnt < b.cnt;
        }
};
class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};
        for(int i=0; i<s.size(); i++) {
            char ch = s[i];
            freq[ch-'a']++;
        }

        // creating the max heap
        priority_queue<Info, vector<Info>, compare> maxHeap;
        //push all the character into the max heap where freq of character is > 0
        for(int i=0; i<26; i++) {
            if(freq[i] > 0) {
                Info temp(i+'a', freq[i]);
                maxHeap.push(temp);
            }
        }

        string ans = "";

        // catch -> humko do character nikalne h
        while(maxHeap.size() > 1) {
            Info first = maxHeap.top();
            maxHeap.pop();
            Info second = maxHeap.top();
            maxHeap.pop();

            ans.push_back(first.val);
            first.cnt--;
            ans.push_back(second.val);
            second.cnt--;

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
            ans.push_back(first.val);
            first.cnt--;
            if(first.cnt > 0) {
                return "";
            }
        }

        return ans;
    }
};