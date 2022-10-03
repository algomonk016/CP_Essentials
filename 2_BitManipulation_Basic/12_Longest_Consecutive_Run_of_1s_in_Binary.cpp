/*
Longest Consecutive Run of 1s in Binary
  Given a non-negative integer n, return the length of the longest consecutive run of 1s in its binary representation.

Constraints
  0 ≤ n < 2 ^ 31

Example:
  Input: 156
  Output: 3
*/ 

#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
  int ans = 0;
  int cnt = 0;
  while(n){
    int last = n&1;
    cnt += last;
    if(!last){
      ans = max(cnt, ans);
      cnt = 0;
    }
    n >>= 1;
  }

  return max(ans, cnt);
}