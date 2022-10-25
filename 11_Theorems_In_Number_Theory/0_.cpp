/*
  Fermat's Theorem
    pow(a, p) is congruent to a mod p
    where p is prime

    pow(a, p) = a
    pow(a, p-1) = 1
    pow(a, p-2) = pow(a, -1)

    (a/b)%p = (a*pow(b, -1))%p
    (a%p * pow(b, p-2)%p)%p

nCr = (n!)/(r! * (n-r)!)
    = (n!)%p * (pow(r, -1)!)%p * (pow(n-r, -1)!)%p

*/

#include "bits/stdc++.h"
using namespace std;
const int p = 1e9 + 7, N = 1e5;
int fact[N];

// O(1)
int mulm(int a, int b){
  return (a%p * b%p)%p;
}

// O(logy)
int powr(int a, int b){
  int ans = 1;
  while(b){
    if(b&1) ans = mulm(ans, a);
    b/=2;
    a = mulm(a, a);
  }

  return ans;
}

// O(logy)
int inv(int a){
  return powr(a, p-2);
}

// O(N)
void calculate_factorials(){
  fact[0] = 1;

  for(int i = 1; i < N; i++){
    fact[i] = mulm(fact[i-1], i);
  }

}

// O(1)
int addm(int a, int b){
  return (a%p + b%p)%p;
}

// O(1)
int subm(int a, int b){
  return ((a-b)%p + p) % p;
}

// O(logy)
int divm(int a, int b){
  return mulm(a, inv(b));
}

// O(logy)
int nCr(int n, int r){
  return mulm(mulm(fact[n], inv(fact[r])), inv(fact[n-r]));
}

// O(logy)
int nPr(int n, int r){
  return mulm(fact[n], inv(fact[n-r]));
}
