#include<iostream>
#include<string>
using namespace std;

// int x = 20;

// void fun(int x) {
//     cout << x << endl;
// }


// class Student {
//     double b;
//     double c;
//     char a;
//     bool d;
// };

int main() {

string str;
cout << sizeof(str);

// cout << sizeof(Student);


// cout << ::x << endl;
// ::x = 4000;

// fun(x);

// cout << "hfbas" << ::x << endl; 


//     int* intPtr = new int(5);

//     // using malloc
//     int *mptr = (int*)malloc(4);
//     *mptr = 10;

//     delete intPtr;
//     free(mptr);

//     // 1D allocation

//     // using new keyword

//     int *newArray = new int[5];

//     // using malloc
//     int* arrMalloc = (int*)malloc(5*sizeof(int));


//     // 2D heap allocation
//     int row = 5;
//     int col = 5;
//     int **ptr2D = new int*[row];
//     for(int i=0; i<row; i++) {
//         ptr2D[i] = new int[col];
//     }

//     // using malloc
//     int** ptr2DMalloc = (int**)malloc(sizeof(int*)* row);
//     for(int i=0; i<row; i++) {
//         ptr2DMalloc[i] =(int*) malloc(sizeof(int)*col);
//     }

//     // delete
//     for(int i=0; i<row; i++) {
//         delete[]ptr2D[i];
//     }

//     delete [] ptr2D;

//     // free
//     for(int i=0; i<row; i++) {
//         free(ptr2DMalloc[i]);
//     }

//     free(ptr2DMalloc);

    return 0;
}