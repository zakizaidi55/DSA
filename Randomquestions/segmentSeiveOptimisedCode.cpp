#include <iostream>
#include<vector>
#include<math.h>
using namespace std;


vector<bool> Seive(int n) {
  // cout << "call recreived for the valiu of n: " << n << endl;
  vector<bool> seive(n+1, true);

  seive[0] = seive[1] = false;

  for(int i=2; i*i<n; i++) {
    if(seive[i] == true) {
    //   int j = 2*i;
        int j = i * i; //first optimisation
      while(j <= n) {
        seive[j] = false;
        j += i;
      } 
    }
  }


  return seive;
}

vector<bool> segSeive(int L, int R) {
  cout << "the value of L " << L <<" and R " << R << endl;
  // get me prime array, I will use it to mark seg seive
  vector<bool>sieve = Seive(sqrt(R));
  vector<int> basePrime;
  for(int i=0; i<sieve.size(); i++) {
      if(sieve[i]) {
          basePrime.push_back(i);
      }
    }

  // cout << "Printing the base prime " << endl;
  // for(int i=0; i<basePrime.size(); i++) {
  //   cout << basePrime[i] << " ";
  // }
  vector<bool>segSeive(R-L+1, true);
  if(L == 1 || L == 0 )
      segSeive[L] = false;
  
  for(auto prime : basePrime) {
      int firstMul = (L/prime) * prime;
      
      if(firstMul < L) {
        firstMul += prime;
      }

      int j = max(firstMul, prime*prime);

      while(j <= R) {
          segSeive[j - L] = false;
          j += prime;
      } 
  }
  return segSeive;
}

int main() {
  // vector<bool>seive = Seive(25);
  
  // for(int i=0; i<=25; i++) {
  //   if(seive[i])
  //     cout << i << " ";
  // }


 
  int L = 110;
  int R = 130;
  vector<bool>ss = segSeive(110,130); 
  cout << "call return successfully" << endl;
  for(int i=0; i<ss.size(); i++) {
    if(ss[i]) {
        cout << i+L << " ";
    }
  }
  return 0;
}