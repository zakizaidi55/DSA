#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void solveForMedian(double &median, priority_queue<int>&maxHeap, priority_queue<int, vector<int>, greater<int> > &minHeap, int& element) {
  if(maxHeap.size() == minHeap.size()) {
    if(element > median) {
      minHeap.push(element);
      median = minHeap.top();
    }

    else {
      maxHeap.push(element);
      median = maxHeap.top();
    }
  }

  else if(maxHeap.size() == minHeap.size()+1) {
    if(element > median) {
      minHeap.push(element);
    }

    else {
      int temp = maxHeap.top();
      maxHeap.pop();
      minHeap.push(temp);
      maxHeap.push(element);
      
    }
     median = (minHeap.top() + maxHeap.top()) / 2.0;
  }

  else if(minHeap.size() == maxHeap.size() + 1) {
    if(element > median) {
      int temp = minHeap.top();
      minHeap.pop();
      maxHeap.push(temp);
      minHeap.push(element);
      
    }

    else {
      maxHeap.push(element);

    }
     median = (minHeap.top() + maxHeap.top()) / 2.0;
  }

}

int main() {
  int arr[] = {12,10,8,4,2,3,15};
  int n = 7;

  // 12 - > 12
  // 10 12 -> 11
  // 8 10 12 ->10
  // 4 8 10 12 -> 9
  // 2 4 8 10 12 ->8
  // 2 3 4 8 10 12 ->6
  // 2 3 4 8 10 12 15 ->8
  priority_queue<int>maxHeap;
  priority_queue<int, vector<int>, greater<int> > minHeap;
  double median = 0;
  for(int i=0; i<n; i++) {
    int element = arr[i];
    
    solveForMedian(median, maxHeap, minHeap, element);
    cout << "Median found : " << median << endl;
  }

  return 0;
}


// =======================================Method 2===============================
class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int> >minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size() == 0 || num < maxHeap.top()) {
            maxHeap.push(num);
        }

        else {
            minHeap.push(num);
        }

        // both heap must have same number of element
        // if not maxHeap must have one more element then min heap
        if(maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        else if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top())/2.0;
        }

        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */