#include<bits/stdc++.h>
using namespace std;

bool isPowerOf2(int n){
  return (n & (n-1)) == 0;
}

bool isPowerOfFour(int n) {
  int cnt = 0;

  int flag = isPowerOf2(n);
  while(flag){
    n >>= 1;
    cnt++;
    flag = isPowerOf2(n) && n > 0;
  }
  
  return (cnt > 0 && cnt&1);
}