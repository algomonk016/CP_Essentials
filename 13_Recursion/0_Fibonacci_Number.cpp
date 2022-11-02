/*
Fibonacci Number
  f(n) = f(n-1) + f(n-2)

  f(0) = 0
  f(1) = 1
*/ 

#include "bits/stdc++.h"
using namespace std;

/*
  Naive Recursive Approach
  Time: O(2^n)
*/ 
int fiboRecursive(int n){
  if(n <= 1){
    return n;
  }

  return fiboRecursive(n-1) + fiboRecursive(n-2);
}

/*
  Memoized Recursive Approach
  Time: O(n)
  Auxiliary Space: O(n)
*/

vector<int> fibo(1e5+1, 0);
int fiboMemoized(int n){
  if(n <= 1){
    return n;
  }

  if(fibo[n]){
    return fibo[n];
  }

  fibo[n] = fiboMemoized(n-1) + fiboMemoized(n-2);
  return fibo[n];
}


/*
  Matrix Exponentiation Approach
  Time: O(n)

  T -> [
    [ 1 1 ]
    [ 0 1 ]
  ]

  F(2) = [
    1
    1
  ]

  F(n) = pow(T, n-2) * F(2)
*/

const int sz = 2;
const int mod = 1e9 + 7;

struct Matrix{
  int m[sz][sz];

  Matrix(){
    memset(m, 0, sizeof(m));
  }

  void identity(){
    for(int i=0; i<sz; i++)
      m[i][i] = 1;
  }

  Matrix operator* (Matrix n){
    Matrix res;
    for(int i=0; i<sz; i++){
      for(int j=0; j<sz; j++){
        for(int k=0; k<sz; k++){
          res.m[i][j] += m[i][k] * n.m[j][k];
          res.m[i][j] %= mod;
        }
      }
    }
    return res;
  }
};

int fiboMatrixExponentiation(int n){
  Matrix T, res;
  res.identity();
  T.m[0][0] = T.m[0][1] = T.m[1][0] = 1;

  if(n == 0) return 0;

  if(n <= 2){
    return 1;
  }

  n -= 2;

  while(n){
    if(n & 1){
      res = res * T;
    }
    T = T * T;
    n >>= 1;
  }

  return (res.m[0][0] + res.m[0][1])%mod;
}
