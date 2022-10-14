/*
  f(n) = a*f(n-1) + b*f(n-2) + c*f(n-3) + d
  t -> [
    [a b c d]
    [1 0 0 0]
    [0 1 0 0]
    [0 0 0 1]
  ]

  f(n) -> [
    f(n)
    f(n-1)
    f(n-2)
    1
  ]
*/

#include <bits/stdc++.h>
using namespace std;

const int sz = 4, mod = 1e9 + 7;
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

int f(int a, int b, int c, int d, int n){
  if(n <= 4){
    return d;
  }

  Matrix res, t;
  res.identity();

  t.m[0][0] = a;
  t.m[0][1] = b;
  t.m[0][2] = c;
  t.m[0][3] = d;

  t.m[1][0] = t.m[2][1] = t.m[3][3] = 1;

  n-=4;

  while(n){
    if(n&1) res = res * t;
    t = t * t;
    n >>= 1;
  }

  int ans = 0;
  for(int i=0; i<sz; i++){
    ans += res.m[0][i];
  }

  return ans;

}

