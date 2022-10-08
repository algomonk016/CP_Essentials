/*
Bitwise AND of Range of Numbers
  Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

Constraints:
  0 <= left <= right <= 2^31 - 1

Example:
  Input: left = 5, right = 7
  Output: 4
*/ 

#include<bits/stdc++.h>
using namespace std;

int rangeBitweseAndOptimized(int left, int right){
  int diff = right - left;
  int ans = 0;

  for(int i=0; i<31; i++){
    int val = (1 << i);
    if(diff/val == 0){
      if(left&val && right &val){
        ans += val;
      }
    }
  }

  return ans;
}

int rangeBitwiseAnd(int left, int right) {  
    int ans = left;
    for(int i=left; i<=right; i++){
        ans &= i;
    }
    
    return ans;
}