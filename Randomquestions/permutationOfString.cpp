#include<iostream>
#include<string>
using namespace std;


void printPermutations(string str, int i) {
    // base case
    if(i >= str.length()) {
        cout << str << " ";
        return;
    }

    for(int j=i; j<str.length(); j++) {
        swap(str[i], str[j]);
        // recursion call
        printPermutations(str, i+1);
        // backtracking
        swap(str[i], str[j]);
    }
}

int main() {

    string str = "abc";
    int i = 0;
    printPermutations(str, i);

    return 0;
}