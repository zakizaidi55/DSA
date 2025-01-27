#include<iostream>
#include<vector>

using namespace std;

void selectionSort(vector<int>&v, int size) {
    for(int i=0; i<size; i++) {
        int minIndex = i;
        for(int j=i+1; j<size; j++) {
            if(v[j] < v[minIndex]) {
                minIndex = j;
            }
        }

        // swap with minIndex
        swap(v[minIndex], v[i]);
    }
}

int main() {
    vector<int>v = {5,4,32,2,1};

    selectionSort(v, 5); 

    for(auto ele: v) {
        cout << ele << " ";
    }
    return 0;
}