#include <bits/stdc++.h>
using namespace std;
// Binary + Modular Exponentiation
// O(logb)

const int mod = 1e9 + 7;
int powr(int a, int b){
  int res = 1;
  while(b){
    if(b&1){
      res *= a, res %= mod;
    }
    a *= a, a %= mod;
    b >>= 1;
  }

  return res;
}

int multiply(int a, int b, int c){
  int res = 0;
  while(b){
    if(b&1){
      res += a, res %= c;
    }

    a += a, a%=c;
    b >>= 1;
  }

  return res;
}