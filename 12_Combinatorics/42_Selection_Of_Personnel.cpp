/*
Selection Of Personnel: https://codeforces.com/problemset/problem/630/F
One company of IT City decided to create a group of innovative developments consisting from 5 to 7 people and hire new employees for it. After placing an advertisment the company received n resumes. Now the HR department has to evaluate each possible group composition and select one of them. Your task is to count the number of variants of group composition to evaluate.

Input
  The only line of the input contains one integer n (7 ≤ n ≤ 777) — the number of potential employees that sent resumes.
  7

Output
  Output one integer — the number of different variants of group composition.
  29

Approach:
  ans = nC5 + nC6 + nC7

  nC7 can be calculated as: n / 1 * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 * (n - 4) / 5 * (n - 5) / 6 * (n - 6) / 7
*/ 

#include<bits/stdc++.h>
using namespace std;

// code 1: building pascal's triangle
int solve1(int n){
  vector<vector<int>> nCr(n+1, vector<int> (n+1, 1));

  for(int i=1; i<=n; i++){
    for(int j=1; j<i; j++){
      nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
    }
  }
  return nCr[n][5] + nCr[n][6] + nCr[n][7];
} 

// code 2, using formula of line 16
long long nCr(int n, int r){
  if(n == r) return 1;
  if(n < r) return 0;

  r = min(r, n-r);

  long long ans = 1;
  for(int i=0; i<r; i++){
    ans *= (n-i);
    ans /= (i+1);
  }

  return max(0LL, ans);
}

long long solve(int n){
  return nCr(n, 5) + nCr(n, 6) + nCr(n, 7);
}