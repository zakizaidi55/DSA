#include<iostream>
#include<string>
#include<cmath>
using namespace std;


void subSeq(string& s) {
    int numSub = pow(2, s.size()); //number of subsequence

    for (int n=0; n<numSub; n++)
    {
        string output = "";
        int num = n;

        // convert num to binary
        int i = 0;
        while(num) {
            // cout << "num-> " << num << endl;
            int b = (num&1);
            // cout << " b-> " << b << endl; 
            if(b){
                // cout << "B-> " << b << endl;
                output.push_back(s[i]);

            }
            i++;
            // cout << b <<" ";
            num >>= 1;
        }
        cout << endl;
        cout << "->" << output << endl;
    }
    
}

int main() {

    string s = "abc";
    subSeq(s);


    return 0;

}