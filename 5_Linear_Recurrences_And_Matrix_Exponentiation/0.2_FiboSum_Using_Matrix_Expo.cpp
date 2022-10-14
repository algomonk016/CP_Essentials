/*
FIBOSUM: https://www.spoj.com/problems/FIBOSUM/

Approach 2:
  T * Fn = Fn+1

  Fn = [    |  Fn+1 = [
    Sn      |       Sn+1
    Fn      |       Fn+1
    Fn-1    |       Fn
  ]         |  ]

  Sn+1 = Sn + Fn+1
       = Sn + Fn + Fn-1
  For Sn+1, we need sum of all three, so [1 1 1]

  Fn+1 = Fn + Fn-1, we need sum of last two, so [0 1 1]

  Fn = Fn, we just need 2nd, so [0 1 0]

  T = [
    [1 1 1]
    [0 1 1]
    [0 1 0]
  ]

  base case: F1 = [
    1
    1
    0
  ]
*/
#include <bits/stdc++.h>
using namespace std;

const int sz = 3;
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

int FiboSum(int n){

  if(n<=0){
    return 0;
  }

  if(n == 1){
    return 1;
  }

  Matrix res, t;
  t.m[0][0] = t.m[0][1] = t.m[0][2] = 1;
  t.m[1][1] = t.m[1][2] = 1;
  t.m[2][1] = 1;

  res.identity();

  n -= 1;

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
  return (FiboSum(m) - FiboSum(n-1) + mod) % mod;
}