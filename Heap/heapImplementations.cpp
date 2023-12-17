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
};

int main() {
  Heap h(20);
  h.insert(10);
  h.insert(20);
  h.insert(5);
  h.insert(11);
  h.insert(6);

  cout <<"Printing the max heap " << endl;

  h.printHeap();

  return 0;
}