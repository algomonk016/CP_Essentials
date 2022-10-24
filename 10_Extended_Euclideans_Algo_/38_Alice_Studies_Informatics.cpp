/*
Alice Studies Informatics
  Today in Informatics class Alice learned about GCD and LCM. Alice is very intelligent, so she solved all the tasks momentarily and now suggests you to solve one of them as well.
  We define a pair of integers (a, b) good, if GCD(a, b) = x and LCM(a, b) = y, where GCD(a, b) denotes the greatest common divisor of a and b, and   LCM(a, b) denotes the least common multiple of a and b.
  You are given two integers x and y. You are to find the number of good pairs of integers (a, b) such that l ≤ a, b ≤ r. Note that pairs (a, b) and (b, a) are considered different if a ≠ b.
  Return the count of good pairs.

Constraints:
  1 <= l <= r <= 10^9
  1 <= x <= y <= 10^9

Example 1:
  Input: l = 1, r = 12, x = 1, y = 12
  Output: 4
  
  Explanation: Good pairs of integers (a, b): (1, 12), (12, 1), (3, 4) and (4, 3).

Approach:
  provided:
    x = gcd(a, b)
    y = lcm(a, b)

    a = c*x
    b = d*x

    gcd(a, b) * lcm(a, b) = a*b
    x * y = a * b
    x * y = c*x * d*x
    y = cdx

    y/x = cd

    ans exists if y%x == 0

*/

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a%b);
}

int solve(int l,int r,int x,int y){
  if(y%x != 0){
    return 0;
  }
  
  int ans = 0;
  l = (l + x - 1)/x;
  r /= x;
  y /= x;
  
  for(int i=1; i*i <= y; i++){
    if(y % i == 0){
      int val1 = i;
      int val2 = y/i;
      
      int isGCD1 = gcd(val1, val2) == 1;    
      int isInRangeLR = (val2 >= l && val2 <= r) && (val1 <= r && val2 >= l);
      
      if(isGCD1 && isInRangeLR){
        ans++;
        ans += val1 != val2;
      }
    }
  }
  
  return ans;
}