/*
Divisibility
  Given an array  arr, return the number of  integers between l and r, inclusive, that are divisible by at least one of the elements in arr.

Constraints:
  1 <= arr.length <= 18
  1 <= arr[i] <= 10^9
  1 <= l <= r <= 10^9

Example:
  Input: l= 579000, r= 987654, a= [1, 2] 
  Output: 408655


Approach: 
  we want total number of divisors for nums in range [L, R]
  so, ans = numberOfDivisors(R) - numberOfDivisorsTill (L-1)
*/

#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n){
  return __builtin_popcount(n);
}

int __lcm(int a, int b){
  return (a*b)/__gcd(a, b);
}

int numDivisible(int l, int r, vector<int> nums){
  int m = nums.size();
  int ans1 = 0, ans2 = 0;
  for(int i=1; i<(1 << m); i++){
    int lcm = 1;
    for(int j=0; j<m; j++){
      if((i>>j)&1){
        lcm = __lcm(nums[j], lcm);
      }
    }

    if(countSetBits(i)&1){
      ans1 += ((l-1)/lcm);
      ans2 += (r/lcm);
    } else{
      ans1 -= ((l-1)/lcm);
      ans2 -= (r/lcm);
    }
  }

  return ans2 - ans1;
}
