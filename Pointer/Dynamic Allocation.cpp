#include <iostream>
using namespace std;

int main() {
//   int* newNum = new int(5);

//   int* mallocNum = (int*) malloc(4); 

//   *mallocNum = 10;

//   cout << newNum << endl;

//   cout << mallocNum << endl;

//   delete newNum;
//   free(mallocNum);



//   1 D allocation

//   int* newArr = new int[5];


//   int* mallocArr = (int*) malloc(4*sizeof(int));

//   delete[] newArr;

//   free(mallocArr);


//   2D allocation in array
  int row = 5;
  int col = 5;
  int** array2D = new int*[row];
  for(int i=0; i<col; i++) {
    array2D[i] = new int[col];
  }


  int** malloc2D = (int**) malloc(5*sizeof(int*));

  for(int i=0; i<row; i++) {
    malloc2D[i] = (int*)malloc(5*sizeof(int));
  }

  return 0;
}