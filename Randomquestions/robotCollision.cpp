class Solution {
public:
    
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int>ans;
        int n = positions.size();
        stack<int>st;

        vector<int>indices(n);

        for(int i=0; i<n; i++) {
            indices[i] = i;
        }

        auto lambda = [&] (int&i, int&j) {
            return positions[i] < positions[j];
        };

        sort(indices.begin(), indices.end(), lambda);

        for(int currentIndex: indices) {
            if(directions[currentIndex] == 'R')
                st.push(currentIndex);
            
            else {
                while(!st.empty() && healths[currentIndex] > 0) {
                    // pop the current robot
                    int topIndex = st.top();
                    st.pop();


                    if(healths[topIndex] > healths[currentIndex]) {
                        healths[topIndex] -= 1;
                        healths[currentIndex] = 0;
                        st.push(topIndex);
                    }

                    else if(healths[topIndex] < healths[currentIndex]) {
                        healths[currentIndex] -= 1;
                        healths[topIndex] = 0;
                    }

                    else {
                        // both have same
                        healths[currentIndex] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }

        for(int i=0; i<n; i++) {
            if(healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }

        return ans;
    }
};