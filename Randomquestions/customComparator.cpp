#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

void print(vector<int> &v) {
  int n = v.size();
  for(int i=0; i<n; i++) {
    cout << v[i] << " "; 
  }
}



void printvv(vector<vector<int> > &v) {
  int n = v.size();
  for(int i=0; i<n; i++) {
    for(int j=0; j<v[i].size(); j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

void bubbleSort(vector<int> &v) {
  int n = v.size();
  for(int i=0; i<n; i++) {
    for(int j=0; j<n-i-1; j++) {
      if(v[j] < v[j+1]) 
        swap(v[j], v[j+1]);
    }
  }
  
}

void insertionSort(vector<int>& v) {
  int n = v.size();
  for(int i=0; i<n; i++) {
    int key = v[i];
    int j = i-1;
    // move element of arr[0..i-1] that are greater than key
    while(j>=0 && v[j] > key) {
      v[j+1] = v[j];
      j--;
    }
    v[j+1] = key;
    
  }
}

void selectionSort(vector<int>&v) {
  int n = v.size();
  for(int i=0; i<n-1; i++) {
    int minIndex = i;
    for(int j=i+1; j<n; j++) {
      if(v[j] < v[minIndex]) 
          minIndex = j; 
    }

    swap(v[i], v[minIndex]);
  }
  
}

bool myComp(vector<int>& a, vector<int>& b) {
  return a[1] < b[1];
}

int main() {
  // vector<int> v = {44,11,22,33,55};
  // bubbleSort(v);

  // selectionSort(v);
  //   print(v);

  // vector<vector<int> > v(5,vector<int>(10));

  // for(int i=0; i<v.size(); i++) {
  //   for(int j=0; j<v[0].size(); j++) {
  //     cin >> v[i][j];
  //   } 
  
  // }

  // for(int i=0; i<v.size(); i++) {
  //   for(int j=0; j<v[i].size(); j++) {
  //     cout << v[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  vector<vector<int> > v;
  int n;
  cin >> n;

  for(int i=0; i<n; i++) {
    
    int a, b;
    cout << "Enter the values of A and B " << endl;
    cin >> a >> b;
    vector<int> temp;
    temp.push_back(a);
    temp.push_back(b);
    v.push_back(temp); 
  }

  cout << "Here is the values " << endl;
  printvv(v);
  cout << "Lets do the sorting " << endl;
  sort(v.begin(), v.end(), myComp);
  printvv(v);
  return 0;
  
  
}