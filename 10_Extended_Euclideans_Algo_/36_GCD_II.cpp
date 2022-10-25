/*
GCD II: https://www.spoj.com/problems/GCD2/ , https://www.codechef.com/problems/GCD2
Frank explained to his friend Felman the algorithm of Euclides to calculate the GCD of two numbers. Then Felman implements its algorithm

int gcd(int a, int b){
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}

and it proposes to Frank that makes it but with a little integer and another integer that has up to 250 digits.
Your task is to help Frank program an efficient code for the challenge of Felman.

Constraints:
  1 <= a <= 40000
  a <= b < 10^250

Example:
  Input: a= 10 , b= "11"
  Output: 1

gcd(7, 12345)

(a+b)%c = a%c + b%c
(a*b)%c = (a%c * b%c)%c

1*10000 + 2*1000 + 3*100 + 4 + 10 + 5

12345 mod 7 = 4
mod = 0 * 10 + 1 mod 7 = 1
    = 1 * 10 + 2 mod 7 = 5
    = 5 * 10 + 3 mod 7 = 53%7 = 4
    = 44 mod 7 = 2
    = 25 mod 7 = 4

gcd(4, 7)
*/

#include "bits/stdc++.h"
using namespace std;

int gcd(int a,int b){
  if(a<b){
    swap(a, b);
  }
  
  if(b == 0){
    return a;
  }
  
  return gcd(b, a%b);
}

int solve(int a, string b){
  if(!a){
    return stoi(b);
  }

  int mod = 0;

  for(auto &i: b){
    mod = (mod * 10 + i - '0')%a;
  }

  return gcd(a, mod);
}