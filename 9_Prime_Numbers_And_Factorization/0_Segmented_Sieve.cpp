/*
SegmentedSieve: https://www.spoj.com/problems/PRIME1/

print prime in range: 10^9

m...........n

the range will be huge, we can't use regular sieve

- so, firstly we do shifting
m-m ........ n-m

- then, store all primes upto sqrt(n)
- mark all the no's which are not prime, using the primes vector
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long int

#define N 100000
int sieveArr[N+1] = {0};
vector<int> primes;
void sieve(){
  for(int i=2; i<=N; i++){
    if(sieveArr[i] == 0){
      primes.emplace_back(i);
      for(int j=i*i; j<=N; j+=i){
        sieveArr[j] = 1;
      }
    }
  }
}

void solve(int testCase) {
  int m, n;
  cin>>m>>n;

  vector<int> segment(n-m+1, 0);

  for(auto &p: primes){
    // stop when p*p > n
    if(p*p > n) break;

    // we need to find the neared starting point
    int start = (m/p)*p;

    if(p >=m and p<=n) start = 2*p;

    // start marking the numbers as not prime from start
    for(int j = start; j<=n; j+=p){
      if(j < m) continue;
      segment[j-m] = 1;
    }
  }

  for(int i=m; i<=n; i++){
    if(segment[i-m] == 0 && i!=1){
      cout<<i<<endl;
    }
  }
  cout<<endl;

}
signed main() {
  // precompute all primes
  sieve();
  int testCase = 1, i = 0;
  cin>>testCase;
  while (i++ != testCase) {
    // cout<<"Case #"<<i<<": ";
    solve(i);
  }

#ifndef ONLINE_JUDGE
  cerr << "Time Taken : " << (float)clock() / CLOCKS_PER_SEC << " seconds" << endl;
#endif

  return 0;
}
