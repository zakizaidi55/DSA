#include<iostream>

using namespace std;

int main() {
    int *intPtr = new int(5);
    int *mPtr = (int*)malloc(4);

    delete intPtr;
    free(mPtr);
    *mPtr = 10;


    // 1D allocation
    int *arr = new int[10];

    int *arrmalloc = (int *)malloc(5 * sizeof(int));
    delete[] arr;
    free(arrmalloc);


    // 2d allocations
    int **ptr2DArr = new int *[5];
    for(int i=0; i<5; i++) {
        ptr2DArr[i] = new int[5];
    }


    int **ptr2DMalloc = (int **)malloc(sizeof(int *) * 4);

    for(int i=0; i<4; i++) {
        ptr2DMalloc[i] = (int *) malloc(sizeof(int) * 4);
    }

    // deallocation
    for(int i=0; i<5; i++) {
        delete[] ptr2DArr[i];
    }
    delete []ptr2DArr;

    for(int i=0; i<4; i++) {
        free(ptr2DMalloc[i]);
    }

    free(ptr2DMalloc);

    return 0;
}