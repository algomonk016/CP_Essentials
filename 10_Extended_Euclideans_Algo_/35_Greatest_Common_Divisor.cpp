/*
Greatest Common Divisor
  Given 2 non-negative integers a and b, find gcd(a, b), GCD of 2 integers a and b is defined as the greatest integer g such that g is a divisor of both a and b.
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int a,int b){
  if(a<b){
    swap(a, b);
  }
  
  if(b == 0){
    return a;
  }
  
  return solve(b, a%b);
}