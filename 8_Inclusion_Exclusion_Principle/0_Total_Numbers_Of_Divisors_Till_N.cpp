/*
Total numbers which are less than 500 and are divisible by first 3 prime numbers

  Primes = {2, 3, 5}

  N2 -> 500/2 -> 250
  N3 -> 500/3 -> 166
  N5 -> 500/5 -> 100
  N23 -> 500/6 -> 83
  N25 -> 500/10 -> 50
  N35 -> 500/15 -> 33
  N235 -> 500/30 -> 18

  250 + 166 + 100
  - 83 - 50 - 33
  + 18
*/

#include "bits/stdc++.h"
using namespace std;

int countSetBits(int n){
  return __builtin_popcount(n);
}

void solve(int testCase) {
  /*ummeed hai ki base case ka socha hoga*/

  int n;
  cin>>n;

  // it can contain non primes too, but we need to calculate lcm for them properly
  vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

  int m = primes.size();

  int ans = 0;
  // generating all subsets of primes array
  for(int i=1; i<(1 << m); i++){
    int lcm = 1;
    for(int j=0; j<m; j++){
      if((i>>j)&1){
        lcm *= primes[j];
      }
    }

    if(countSetBits(i)&1){
      ans += (n/lcm);
    } else{
      ans -= (n/lcm);
    }
  }

  cout<<ans<<endl;
}
