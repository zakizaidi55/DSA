#include <iostream>
#include<queue>
using namespace std;

int getKthSmallestElement (int *arr, int n, int k) {
  priority_queue<int>pq; //create max heap

  for(int i=0; i<k; i++) {
    int element = arr[i];
    pq.push(element);
  }

  for(int i=k; i<n; i++) {
    int element = arr[i];
    if(element < arr[i]) {
      if(element < pq.top()) {
        pq.pop();
        pq.push(element);
      }
    }
  }

  int ans = pq.top();
  return ans;
}
int main() {
  int arr[] = {3,4,5,1,34,5,1};
  int n = 7;
  int ans = getKthSmallestElement(arr, n, 4);
  cout << ans;
  return 0;
}