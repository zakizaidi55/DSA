#include<iostream>

using namespace std;

void merge(int arr[], int start, int end, int mid) {
    // copy create of left and right sorted array
    int leftArrayLength = mid-start+1;
    int rightArrayLength = end - mid;

    int *arr1 = new int[leftArrayLength];
    int *arr2 = new int[rightArrayLength];

    int mainArrayIndex = start;
    for(int i=0; i<leftArrayLength; i++) {
        arr1[i] = arr[mainArrayIndex];
        mainArrayIndex++;
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<rightArrayLength; i++) {
        arr2[i] = arr[mainArrayIndex];
        mainArrayIndex++;
    }
    // merge sorted array logic into the original array
    int i = 0; //arr1
    int j = 0; //arr2
    mainArrayIndex = start; //arr
    while(i < leftArrayLength && j < rightArrayLength) {
        if(arr1[i] < arr2[j]) {
            arr[mainArrayIndex++] = arr1[i++];
        }

        else {
            arr[mainArrayIndex++] = arr2[j++];
        }
    }

    //copy logic
    while(i < leftArrayLength) {
        arr[mainArrayIndex++] = arr1[i++];
    }

    while(j < rightArrayLength) {
        arr[mainArrayIndex++] = arr2[j++];
    }

    delete[]arr1;
    delete[]arr2;
}

void mergeSort(int arr[], int start, int end) {
    if(start > end || start == end) 
        return;

    // ek bade array ko 2 part m divide karte the
    int mid = (start+end)/2;
    // 2 part m divide karke, left part ko rec se solve karate the
    mergeSort(arr, start, mid);
    // right part ko rec se solve karate the
    mergeSort(arr, mid+1, end);
    // recursion ne jo sorted arrays diye h unko merge karte the
    merge(arr, start, end, mid);
}

int main() {
    int arr[] = {7,2,4,3,1,5};
    int size = 6;
    int start = 0;
    int end = size-1;

    mergeSort(arr, start, end);
    cout << "Printing the sorted array " << endl;

    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}


