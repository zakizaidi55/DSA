#include<iostream>

using namespace std;

// --------------------Method 1-----------------------------
void findMissing(int arr[], int n) {
    for(int i=0; i<n; i++) {
        int index = abs(arr[i]);
        if(arr[index-1] > 0) {
            arr[index - 1] *= -1;
        }
    }
    // all positive indexes are missing
    for(int i=0; i<n; i++) {
        if(arr[i] > 0)
            cout << i+1 << endl;
    }
}

// -------------Method2---------------------
void findMissingUsingSorting(int arr[], int n) {
    int i = 0;
    while(i < n) {
        cout << "Iteration " << i << endl;
        int index = arr[i] - 1;
        if(arr[i] != arr[index]) {
            swap(arr[i], arr[index]);
        }
        else {
            i++;
        }
        
    }

    for(int i=0; i<n; i++) {
        if(arr[i] != i+1)
            cout << i+1 << " ";
    }
}

int main() {

    int arr[] = {1,3,5,4,3};
    int n = sizeof(arr)/sizeof(int);
    // findMissing(arr, n);
    findMissingUsingSorting(arr, n);
}