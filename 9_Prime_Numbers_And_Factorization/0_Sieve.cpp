/*
  Sieve: O(NloglogN)
  Start with i=2, mark all multiples of 2 non prime
  i++, mark all multiples of i, non prime

  all indexes which are unmarked are primes
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define N 1000000

void primeSieve(vector<int> &sieve){
  // mark 1 and 0 as not prime
  sieve[1] = sieve[0] = 0;

  // start from 2 and mark all multiples of ith number as not prime
  for(int i=2; i<=N; i++){
    if(sieve[i]){
      for(int j=i*i; j<=N; j+=i){
        sieve[j] = 0;
      }
    }
  }
}

signed main(){
  vector<int> sieve(N, 1);
  primeSieve(sieve);
}