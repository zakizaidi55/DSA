class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;

        int ans = 0;

        for(int i=0; i<height.size(); i++) {
            while(!st.empty() && height[st.top()] < height[i]) {
                int curr = st.top(); // curr index height jo do end pillars k bich m h
                st.pop();

                if(st.empty()) {
                    break;
                }

                int width = i - st.top() - 1; // difference between 2 end pillars

                
                int minHeight = min(height[i], height[st.top()]);
                // catch yha par galti karta hu
                int finalHeight = minHeight - height[curr]; // yeh isliye kara - kyuki bich m agr zyada jinti hogi toh wha water fill nhi hoga

                ans+= finalHeight * width;
            }

            st.push(i);
        }

        return ans;
    }
};