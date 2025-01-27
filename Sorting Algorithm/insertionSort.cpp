#include<iostream>
#include<vector>

using namespace std;

void insertionSort(vector<int>&v, int size) {
    for(int i=1; i<size; i++) {
        int key = v[i];
        int j = i-1;

        while(j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

int main() {
    vector<int>v = {5,4,3,2,1};

    insertionSort(v, 5); 

    for(auto ele: v) {
        cout << ele << " ";
    }
    return 0;
}