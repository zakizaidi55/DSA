#include<iostream>
#include<stack>
#include<vector>


using namespace std;

vector<int> previosSmallerElement(int *arr, int size, vector<int>&ans) {
    stack<int>st;
    st.push(-1);
    for(int i=0; i<size; i++) {
        int currElement = arr[i];
        // find the ans for current element
        while(st.top() >= currElement) {
            st.pop();
        }

        ans[i] = st.top();
        st.push(currElement);
    }

    return ans;
}

int main() {

    int arr[] = {8,4,6,2,1};
    int size = 5;
    vector<int>ans(size);
    ans = previosSmallerElement(arr,size,ans);
    for(auto i : ans) {
        cout << i << endl;
    }

    return 0;
}