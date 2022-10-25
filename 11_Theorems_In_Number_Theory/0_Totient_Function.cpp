/*
  Number of integers less than n that are coprime to n
    i.e gcd(x, n) = 1
    brute force approach:
      O(N)
    
    totient function:
      f(n) = n * pie (p, p is prime that divides n) (1 - 1/p)

      f(10) = 10 * (1 - 1/2) * (1 - 1/5)

  Q: number of x such that gcd(n, x) = g
    gcd(n, x) = g
    gcd(n/g, x/g) = 1
    gcd(n', x') = 1
    so, we need to find number of x' that are coprime with n'
*/

#include "bits/stdc++.h"
using namespace std;

const int N = 1e5;

int isPrime[N] = {0};
vector<int> tot(N);
void generatePrimes(){
  isPrime[2] = 1;

  for(int i = 3; i < N; i += 2) isPrime[i] = 1;

  for(int i = 3; i < N; i += 2){
    if(isPrime[i]){
      for(int j = i*i; j < N; j += i){
        isPrime[j] = 0;
      }
    }
  }
}


void totientFunction(){
  iota(tot.begin(), tot.end(), 0);

  for(int i=2; i < N; i++){
    if(isPrime[i]){

      // all multiples of i
      for(int j=i; j<N; j+=i){
        tot[j] /= i;
        tot[j] *= i-1;
      }
    }
  }
}

void pre(){
  generatePrimes();
  totientFunction();
}

void solve(int testCase) {
  int n;
  cin>>n;

  cout<<tot[n]<<endl;
}