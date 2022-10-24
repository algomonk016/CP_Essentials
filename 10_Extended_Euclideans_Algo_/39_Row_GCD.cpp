/*
Row Gcd
  You are given two positive integer sequences a1, ... ,an and b1, ... ,bm. For each j=1, ... ,m find the greatest common divisor of a1+bj, ... ,an+bj.
  return an array containing answer for each j=1,...,m respectively.

Constraints:
  1 <= n, m <= 2*10^5
  1 <= ai, bj <= 10^9

Example:
  Input: n= 4, m= 4, a= {1, 25, 121, 169}, b= {1, 2, 7, 23}
  Output: {2, 3, 8, 24}
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int n,int m, vector<int> a, vector<int> b){
  int gcd = 0;
  vector<int> ans;

  for(int i=1; i<n; i++){
    a[i] = abs(a[i]-a[0]);
    gcd = __gcd(gcd, a[i]);
  }

  for(auto &i: b){
    ans.emplace_back(__gcd(a[0]+i, gcd));
  }

  return ans;
}