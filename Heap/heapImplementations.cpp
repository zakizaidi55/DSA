#include <iostream>
using namespace std;

class Heap {
  public:
    int *arr;
    int capacity;
    int size;

    Heap(int capacity) {
      this->size = 0;
      this->capacity = capacity;
      this->arr = new int[capacity];
    }

    void insert(int val) {
      if(size == capacity) {
        cout << "heap overflow " << endl; 
        return;
      } 
      // size will increase when the element is insert
      size++;
      int index = size;
      arr[index] = val;

      // take the val to its correct index 
      while(index > 1) {
        int parentIndex = index/2;
        if(arr[index] > arr[parentIndex]) {
          swap(arr[index], arr[parentIndex]);
          index = parentIndex;
        }

        else {
          break;
        }
      }

    }

    void printHeap() {
      for(int i=0; i<=size; i++) {
        cout << arr[i] << " ";
      }
    }

    int deleteFromHeap() {
      int answer = arr[1];
      // repleacement
      arr[1] = arr[size];
      // last element ko delete kardo uski original position se
      size--;

      int index = 1;

      while(index < size) {
        int leftChildIndex = 2*index;
        int rightChildIndex = 2*index+1;


        // find out which is greater
        int largestIndex = index;

        if(leftChildIndex <= size && arr[largestIndex] < arr[leftChildIndex]) {
          largestIndex = leftChildIndex;
        }
        if(rightChildIndex <= size && arr[largestIndex] < arr[rightChildIndex]) {
          largestIndex = rightChildIndex;
        }

        if(index == largestIndex) {
          break;
        }

        else {
          swap(arr[index], arr[largestIndex]);
          index = largestIndex;
        }
      }

      return answer;
    }
};

void heapify(int *arr, int n, int index) {
  int leftChildIndex = 2*index;
  int rightChildIndex = 2*index+1;

  int largestIndex = index;

  if(leftChildIndex <= n && arr[leftChildIndex] > arr[largestIndex]) {
    largestIndex = leftChildIndex;
  }

  if(rightChildIndex <= n && arr[rightChildIndex] > arr[largestIndex]) {
    largestIndex = rightChildIndex;
  }

  if(index != largestIndex) {
    swap(arr[index] , arr[largestIndex]);
    // recursion call
    index = largestIndex;
    heapify(arr, n, index);
  }
}


void buildHeap(int arr[], int n) {
    for(int index = n/2; index > 0; index--) {
        heapify(arr, n, index);
    }
}


void heapSort(int arr[], int n) {
    while(n != 1) {
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}

int main() {
//   Heap h(20);
//   h.insert(10);
//   h.insert(20);
//   h.insert(5);
//   h.insert(11);
//   h.insert(6);

//   cout <<"Printing the max heap " << endl;

//   h.printHeap();
    // catch -> 0 base indexing h isliye 0th index par -1 dal diya
    int arr[] = {-1,5,10,15,20,25,12};
    int n = 6;
    buildHeap(arr, 6);
    cout << "printing the heap " << endl;
    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, 6);
    cout << "printing the heap after sorting " << endl;
    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }

  return 0;
}