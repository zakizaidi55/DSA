class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int firstMaxNum = nums[nums.size()-1];
        int secondMaxNum = nums[nums.size()-2];

        int firstSmallNum = nums[0];
        int secondSmallNum = nums[1];

        int ans = (firstMaxNum*secondMaxNum) - (firstSmallNum*secondSmallNum);

        return ans;
    }
};



// =============================================Second Method using Heap====================================
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        priority_queue<int> maxPq;
        priority_queue<int, vector<int>, greater<int> >minPq;

        for(int n: nums) {
            maxPq.push(n);
            minPq.push(n);
        }

        int a = maxPq.top();
        cout << "a " << a << endl;
        maxPq.pop();
        int b = maxPq.top();
        cout << "b " << b << endl;
        maxPq.pop();

        int z = minPq.top();
        cout << "z " << z << endl;
        minPq.pop();
        int w = minPq.top();
        cout << "w " << w << endl;
        minPq.pop();

        int ans = (a*b) - (z*w);

        return ans;

    }
};