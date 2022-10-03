/*
Hamming Distance
  The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
  Given two integers x and y, return the Hamming distance between them.

Constraints:
  0 <= x, y <= 2^31 - 1

Example :
  Input: x = 1, y = 4
  Output: 2
*/ 

#include<bits/stdc++.h>
using namespace std;

int hammingDistance(int n, int m) {
  int ans = 0;
  while(1){
    if(!n && !m){
        break;
    }
    ans += (n&1) != (m&1);
    m >>= 1;
    n >>= 1;
  }
  return ans;
}