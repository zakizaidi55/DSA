#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

int getQuotient(int divisor, int divident) {
  int s  = 0;
  int e = divident;
  int mid = s + (e-s)/2;
  int ans = 0;

  while(s <= e) {
    if(mid*divisor == divident) {
      return mid;
    }
    if(mid*divisor < divident) {
      ans = mid;
      s = mid+1;
    }
    else {
      e = mid-1;
    }

    mid = s+(e-s)/2;
  }

  return ans;
  
}

int searchNearlySorted(int arr[], int n, int target) {
  int s = 0;
  int e = n-1;
  int mid = s+ (e-s)/2;

  while(s <= e) {
    if(mid-1 >= 0 && arr[mid - 1] == target) {
      return mid-1;
    }
    if(arr[mid] == target)
        return mid;
    if( mid+1 < n && arr[mid+1] == target) 
        return mid + 1;
    
    if(target > arr[mid])
        s = mid+2;

    else {
      e = mid-2;
    }
    mid = s + (e-s)/2;
  }
  return -1;
}

int findOddOccuringElement(int arr[], int n) {
  int s = 0;
  int e = n-1;
  int mid = s + (e-s)/2 ;

  while(s <= e) {
    if(s == e) 
        return s;

    if(mid & 1) {
      //odd index
      if(mid-1 > 0 && arr[mid] == arr[mid-1]) {
        s = mid + 1;
      }
      else {
        e = mid - 1;
      }
    } 

    else {
      // even index
      if( mid+1 < n && arr[mid] == arr[mid + 1]) {
        // right jao
        s = mid + 2;
      }

      else {
        // whether I am on right part or over the ans thats why e = mid kar rha hu because e = mid-1 se ans lost ho jata h
        e = mid;
      }
    }
    mid = s + (e-s)/2;
  }

  return -1;
}

int main() {
  // int divisor = -5;
  // int divident = 35;
  // if(divisor == 0) {
  //   cout << 0 << endl;
  //   return 0;
  // }

  // if(divisor == 0) {
  //   cout << INT_MAX << endl;
  //   return 0;
  // }
      

  // int ans = getQuotient(abs(divisor), abs(divident));
  // // now we have to decide which sign +ve or -ve
  // if((divisor > 0 && divident < 0) || (divisor < 0 && divident > 0)) {
  //   ans = 0 - ans;
  // }
  // cout << "Final ans is " << ans << endl;

  // int arr[] = {20,10,30,50,40,70,60};
  // int n = 7;
  // int target = 690;
  // int targetIndex = searchNearlySorted(arr, n, target);
  // if(targetIndex == -1)  {
  //   cout << "Ans is not found " << endl;
  // }

  // else {
  //   cout << "Ans is found at index " << targetIndex << endl; 
  // }

  int arr [] = {10,10,2,2,3,3,5,5,6,6,7,7,10};
  int n = 13;
  int ansIndex = findOddOccuringElement(arr, n);
  cout << "final ans is " << arr[ansIndex] << endl;
  return 0;
}