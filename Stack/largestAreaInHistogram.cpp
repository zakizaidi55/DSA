class Solution {
public:

vector<int> previosSmallerElement(vector<int>&arr) {
    vector<int> ans(arr.size());
    stack<int>st;
    st.push(-1);
    for(int i=0; i<arr.size(); i++) {
        int currElement = arr[i];
        // find the ans for current element
        // catch -> possibility is that we area accessing the arr[-1] because in stack -1 was present
        while(st.top() != -1 && arr[st.top()] >= currElement) {
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

vector<int> NextMinElement(vector<int>& arr) {
    vector<int>ans(arr.size());
    stack<int>st;
    st.push(-1);
    for(int i=arr.size()-1; i>=0; i--) {
        int currElement = arr[i];
        // find the ans for current element
        // catch -> possibility is that we area accessing the arr[-1] because in stack -1 was present
        while(st.top() != -1 && arr[st.top()] >= currElement) {
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

    int largestRectangleArea(vector<int>& heights) {
        vector<int>next = NextMinElement(heights);
        // catch to make sure that there should be no element as -1 in next array
        for(int i=0; i<heights.size(); i++) {
    
            if (next[i] == -1) {
                next[i] = heights.size();
            }
        }
        vector<int>prev = previosSmallerElement(heights);

        vector<int>area(next.size());
        for(int i=0; i<next.size(); i++) {
            int width = next[i] - prev[i] - 1;
            int height = heights[i];

            int currArea = width * height;
            area[i] = currArea;
        }

        int maxi = INT_MIN;
        for(int i=0; i<area.size(); i++) {
            maxi = max(maxi, area[i]);
        }


        return maxi;
    }
};