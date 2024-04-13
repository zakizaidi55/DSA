class Solution {
    vector<int>nextSmallerElement(vector<int>& arr) {
        vector<int>ans(arr.size());
        stack<int>st;
        st.push(-1);

        for(int i=arr.size()-1; i>=0; i--) {
            int curr = arr[i];

            while(st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int>prevSmallerElement(vector<int>& arr) {
        vector<int>ans(arr.size());
        stack<int>st;
        st.push(-1);

        for(int i=0; i<arr.size(); i++) {
            int curr = arr[i];
            while( st.top() != -1 && arr[st.top()] >= curr ) {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>next = nextSmallerElement(heights);
        vector<int>prev = prevSmallerElement(heights);

        for(int i=0; i<next.size(); i++) {
            if(next[i] == -1) {
                next[i] = heights.size();
            }
        }
        int maxi = INT_MIN;
        vector<int>area(next.size());
        for(int i=0; i<next.size(); i++) {
            int width = next[i] - prev[i] - 1;
            int length = heights[i];

            int currArea = width*length;
            maxi = max(currArea, maxi);
        }

        return maxi;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int> >v;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i<n; i++) {
            vector<int>t;
            for(int j=0; j<m; j++) {
                t.push_back(matrix[i][j] - '0');
            }

            v.push_back(t);
        }

        int area = largestRectangleArea(v[0]);
        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                // lets update curr row with previous values
                if(v[i][j]) {
                    v[i][j] += v[i-1][j];
                }

                else {
                    v[i][j] = 0;
                }
            }

            area = max(area, largestRectangleArea(v[i]));
        }

        return area;
    }
};