#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e6+1;
vector<int> primes(N, 0);
vector<int> primesCount(N, 0);

void primeSieve(){
  primes[2] = 1;
  for(int i=3; i<=N; i+=2) primes[i] = 1;
  for(int i=3; i<=N; i+=2){
    if(primes[i]){
      for(int j=i*i; j<=N; j+=i) primes[j] = 0;
    }
  }
}

void pre(){
  for(int i=1; i<N; i++){
    primesCount[i] = primesCount[i-1] + primes[i];
  }
}

void solve() {
  primeSieve();
  pre();

  int q;
  cin>>q;

  while(q--){
    int l, r;
    cin>>l>>r;
    cout<<primesCount[r] - primesCount[l-1]<<endl;
  }

}
