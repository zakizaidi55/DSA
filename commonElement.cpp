#include<iostream>
#include<set>
# define size 10

using namespace std;

void displayArr(int ansArr[], int n){
   for( int i = 0; i < n; i++ ){
      cout << ansArr[ i ] << ", ";
   }
   cout << endl;
}

void findCommonElement( int arr1[], int n, int arr2[], int m, int ansArr[], int &k ) {
   k = 0;
   for( int i = 0; i < n; i++ ) {
      for( int j = 0; j < m; j++ ) {
         if( arr1[ i ] == arr2[ j ] ) {
            ansArr[ k ] = arr1[ i ];
            k = k + 1;
         }
      }
   }
}

int main() {
   int arr1[ size ] = { 1,2,5,3,5 };
   int n = 5;
   
   int arr2[ size ] = { 1,2,2,6,7,5 };
   int m = 8;
   
   int ansArr[ size ];
   int k = 0;
   
  set<int>New_set;
  
   
   findCommonElement( arr1, n, arr2, m, ansArr, k );
   for( int i = 0; i < k; i++ ){
      New_set.insert(ansArr[i]);
   }
//    cout << "The common elements are: ";
//    displayArr( ansArr, k ); 

    for(auto x: New_set) {
        if(x==0) {
            continue;;
            
        }
        cout << x << endl;
    }
}