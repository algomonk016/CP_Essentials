/*
Calculate Fibonacci of numbers till 1e18
  fib[i] = fib[i-1] + fib[i-2]

  t -> [ [1 1], [1 0]]
  res -> [ [1 0], [0 1] ]

  initial -> [1, 1]  --> [t[2], t[1]]

  t * f(n) = f(n + 1)

  t * f(2) = f(3)
  t * f(3) = f(4)
  t * f(4) = f(5)
  t * f(5) = f(6)

  t * (t * f(4)) = f(6)
  t * (t * (t * f(3))) = f(6)
  ....

  pow(t, n-2)*f(2) = f(n)
*/ 
#include "bits/stdc++.h"
using namespace std;
#define int long long int

const int mod = 1e9 + 7;
const int sz = 2;

struct Matrix{
  int matrix[sz][sz];

  Matrix(){
    memset(matrix, 0, sizeof(matrix));
  }

  void identity(){
    for(int i=0; i<sz; i++){
      matrix[i][i] = 1;
    }
  }

  Matrix operator* (Matrix second){
    Matrix res;
    for(int i=0; i<sz; i++){
      for(int j=0; j<sz; j++){
        for(int k=0; k<sz; k++){
          res.matrix[i][j] += matrix[i][k] * second.matrix[j][k];
          res.matrix[i][j] %= mod;
        }
      }
    }

    return res;
  }

};

int matrixExponentationFibonacci(int n){

  if(n <= 2){
    return 1;
  }

  Matrix res;
  res.identity();

  Matrix t;
  t.matrix[0][0] = t.matrix[0][1] = t.matrix[1][0] = 1;

  n -= 2;

  while(n){
    if(n & 1) res = res * t;
    t = t * t;
    n >>= 1;
  }

  return (res.matrix[0][0] + res.matrix[0][1])%mod;

}

signed main(){
  int n;
  cin>>n;

  cout<<matrixExponentationFibonacci(n)<<endl;

  return 0;
}
