for(int i=0; i<size; i--) {
        int currElement = arr[i];
        // find the ans for current element
        while(st.top() >= currElement) {
            st.pop();
        }

        ans[i] = st.top();
        st.push(currElement);
    }

    retur