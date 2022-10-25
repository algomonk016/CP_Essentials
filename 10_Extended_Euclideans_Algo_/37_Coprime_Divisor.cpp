/*
Coprime Divisor: https://www.interviewbit.com/problems/largest-coprime-divisor/
  You are given two positive numbers a and b. You need to find the maximum valued integer x such that:
  x divides a i.e. a % x = 0
  x and b are co-prime i.e. gcd(x, b) = 1

Constraints:
  2 <= a, b <= 10^9

Example:
  Input: a = 30, b = 12
  Output: 5
*/

#include "bits/stdc++.h"
using namespace std;

int gcd (int a, int b){
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a%b);
}

int solve(int a, int b){
  while(gcd(a, b) != 1){
    a/=gcd(a, b);
  }
  return a;
}