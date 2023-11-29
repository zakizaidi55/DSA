#include<iostream>
#include<queue>
using namespace std;


int main() {

    string str = "facfdcaa";
    queue<char>q;

    int freq[26] = {0};

    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        freq[ch-'a']++;
        q.push(ch);

        // answer find
        while(!q.empty() ) {
            char frontCharacter = q.front();
            cout << "front character -> " << frontCharacter << endl;
            if(freq[frontCharacter-'a'] > 1) {
                // it is not the answer
                q.pop();
            }

            else {
                // == 1 case, it is the answer
                cout << frontCharacter << "->" << endl ;
                break;
            }
        }
        if(q.empty()) {
            cout << "#" << "->";
        }
    }

    return 0;
}