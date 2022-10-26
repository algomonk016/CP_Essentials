/*

Blog: https://www.topcoder.com/thrive/articles/catalan-number-and-its-application

Count Trees:
  given N, find number of BST that can be formed using N nodes.

Approach:
  f(N) = Sigma i=1 to n, f(i-1) * f(N-i)

  base case, f(0) = f(1) = 1
*/ 

#include "bits/stdc++.h"
using namespace std;
#define int long long int

// approach 1: dp
int CatNum(int n){
  vector<int> cat(n+1, 1);

  for(int i=2; i<=n; i++){
    cat[i] = 0;
    for(int j=0; j<i; j++){
      cat[i] += cat[j] * cat[i-j-1];
    }
  }

  return cat[n];
}

// approach 2: binomial coefficient
int binomialCatNum(int n, int k){
  int res = 1;
  if(k > n-k) k = n-k;

  for(int i=0; i<k; i++){
    res *= (n-i);
    res /= (i+1);
  }

  return res;
}

int cat(int n){
  int c = binomialCatNum(2*n, n);
  return c/(n+1);
}