#include<iostream>
#include<vector>

using namespace std;

void printSpiralMatrixCol(vector<vector<int> >& v) {

    int m = v.size();
    int n = v[0].size();
    for(int startCol=0; startCol<n; startCol++) {
        if((startCol & 1) == 0) {
            // even col
            for(int i=0; i<m; i++) {
                cout << v[i][startCol] << " ";
            }
        }

        else {
            for(int i=m-1; i>=0; i--) {
                cout << v[i][startCol] << " ";
            }
        }
    }

}

void printSpiralMatrixRow(vector<vector<int> >& v) {
    int m = v.size();
    int n = v[0].size();

    for(int startRow=0; startRow<m; startRow++) {
        if((startRow & 1) == 0) {
            // even row
            for(int i=0; i<n; i++) {
                cout << v[startRow][i] << " ";
            }
        }

        else {
            for(int i=n-1; i>=0; i--) {
                cout << v[startRow][i] << " ";
            }
        }
    }
}


int main() {
    vector<vector<int> > v {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    printSpiralMatrixCol(v);
    printSpiralMatrixRow(v);

}