#include<iostream>
using namespace std;

class NStack {
    public:
        int *arr, *top, *next;
        int n; 
        int size;
        int freeSpot;

        NStack(int _n, int _s) :n(_n), size(_s){
            freeSpot = 0;
            arr = new int[_s];
            next = new int[_s];
            top = new int[n];

            for(int i=0; i<n; i++) {
                top[i] = -1;
            }

            for(int i=0; i<size; i++) {
                next[i] = i+1;
            }

            next[size-1] = -1;
        }

        bool push(int X, int m) {
            if(freeSpot == -1)
                return false;
            
            // 1. find the index
            int index = freeSpot;

            // 2 update free spot
            freeSpot = next[index];

            // 3. insert
            arr[index] = X;

            // 4. update next
            next[index] = top[m-1];

            // 5 update top
            top[m-1] = index;

            return true; 
        } 

        // pop from m stack
        int pop(int m) {
            if(top [m-1] == -1) {
                return -1;
            }

            int index = top[m-1];

            top[m-1] = next[index];

            int poppedElement = arr[index];

            next[index] = freeSpot;

            freeSpot = index;

            return poppedElement;
 
        }

        ~NStack() {
            delete[]arr;
            delete[]next;
            delete[]top;
        }


};

int main() {

    NStack s(3,6);

    cout << s.push(10,1) << endl;

    return 0;
}