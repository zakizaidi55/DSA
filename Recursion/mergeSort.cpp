#include <iostream>
using namespace std;

void merge(int arr[], int s, int e) {
  cout << "s values -> " << s << endl;
  cout << "e values -> " << e << endl;
  int mid = s + (e-s)/2;
  int leftLen = mid - s + 1;
  int rightLen = e - mid;

  // create left array
  int *left = new int[leftLen];

  // create right array
  int *right = new int[rightLen];

  // copy values from original array to left array
  int k = s; // k -> starting index of left array values in original arrays
  for(int i = 0; i < leftLen; i++) {
    left[i] = arr[k++];
  } 

  // copy values from original array to right array
  k = mid+1;
  for(int i = 0; i < rightLen; i++) {
    right[i] = arr[k++];
  
  }

  // actual merge logic
  // left array is already sorted
  // right array is also sorted

  int leftIndex = 0;
  int rightIndex = 0;

  int mainArrayIndex = s; //catch -> chances of error
  while(leftIndex < leftLen && rightIndex < rightLen) { 
    if(left[leftIndex] < right[rightIndex] ) {
      arr[mainArrayIndex++] = left[leftIndex++];
    }

    else {
      arr[mainArrayIndex++] = right[rightIndex++];
    }
  }
  // 2 more cases exist
  // case 1-> left array finished, some elements remaining in right array

  while(rightIndex < rightLen) {
    arr[mainArrayIndex++] = right[rightIndex++];
  }

  // case 2-> right array finished, some elements remaining in left array
  while(leftIndex < leftLen) {
    arr[mainArrayIndex++] = left[leftIndex++];
  }

  // deallocation of memory
  delete[] left;
  delete[] right;
  
}

void mergeSort(int arr[], int s, int e) {
  
  if(s > e) {
    // invalid array
    return;
  }

  if(s == e) {
    // single element
    return;
  }

  int mid = s + (e-s)/2;
  // s->mid = left array
  //mid+1->e = right array
  
  // recursive call for left array
  mergeSort(arr, s, mid);

  
  // recursive call for right array
  mergeSort(arr, mid+1, e);

  // merge two sorted arrays
  merge(arr, s, e);
  
}

int main() {
  int arr[] = {20,60,55,15,45,30,72};
  int size = 7;

  int s = 0;
  int e = size-1;


  cout << "before merge sort " << endl;
  for(int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;
  mergeSort(arr, s, e);

  cout << "After merge sort " << endl;
  for(int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
}