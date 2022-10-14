/*
FIBOSUM: https://www.spoj.com/problems/FIBOSUM/

The Fibonacci sequence is defined by the following relation:
F(0) = 0
F(1) = 1
F(N) = F(N - 1) + F(N - 2), N >= 2
Your task is very simple. Given two non-negative integers N and M, you have to calculate the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.

Approach 1: (WA)
  f(n) = f(n-1) + f(n-2)

  f(n-2) = f(n) - f(n-1)
  f(n-3) = f(n-1) - f(n-2)
  f(n-4) = f(n-2) - f(n-3)
  f(n-5) = f(n-3) - f(n-4)
  ....
  f(0) = f(2) - f(1)
  -------------------------------------
  f(0) + f(1) + f(2) + .... + f(n-2) =  f(n) - f(1)
  s(n-2) = f(n) - 1
  s(n) = f(n+2) - 1

  using prefix sum property
  s(n....m) = s(m) - s(n-1)
            = f(m+2) - 1 - (f(n+1) - 1)
            = f(m+2) - f(n+1)

*/

#include <bits/stdc++.h>
using namespace std;

const int sz = 2;
const int mod = 1e9 + 7;
struct Matrix{
  int m[sz][sz];
  Matrix(){
    memset(m, 0, sizeof(m));
  }

  void identity(){
    for(int i=0; i<sz; i++){
      m[i][i] = 1;
    }
  }

  Matrix operator* (Matrix m2){
    Matrix res;

    for(int i=0; i<sz; i++){
      for(int j=0; j<sz; j++){
        for(int k=0; k<sz; k++){
          res.m[i][j] += m[i][k] * m2.m[k][j];
          res.m[i][j] %= mod;
        }
      }
    }

    return res;
  }
};

int getFibo(int n){
  Matrix res, t;
  t.m[0][0] = t.m[0][1] = t.m[1][0] = 1;

  res.identity();

  if(n<=2){
    return 1;
  }

  n -= 2;

  while(n){
    if(n & 1){
      res = res * t;
    }

    t = t * t;
    n >>= 1;
  }

  return (res.m[0][0] + res.m[0][1])%mod;
}

int fibSum(int n,int m){
  return (getFibo(m+2) - getFibo(n+1) + mod) % mod;
}
