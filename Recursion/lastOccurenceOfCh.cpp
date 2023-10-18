#include<iostream>

using namespace std;


void lastOccCh(string& s, char x, int index, int& ans) {
    // base case
    if(index >= s.size()) {
        return;
    }

    // one case
    if(s[index] == x) {
        ans = index;
    }

    // recursion call
    lastOccCh(s, x, index+1, ans);
}


void lastOccRTL(string& s, char x, int index, int& ans ) {
    // base case
    if(index < 0) {
        return;
        
    }
    // one case
    if(s[index] == x) {
        ans = index;
        return;
    }

    // recursion call
    lastOccRTL(s,x,index-1, ans);
}

int main() {

    string s;
    cin >> s;
    char x;
    cin >> x ;
    int ans = -1;
    int i = s.size() - 1;

    // lastOccCh(s, x, 0, ans);

    lastOccRTL(s, x, i, ans);


    cout << ans << endl;



    return 0;

}