/*
Remainders Game: https://codeforces.com/problemset/problem/687/B

Today Pari and Arya are playing a game called Remainders.
Pari chooses two positive integer x and k, and tells Arya k but not x. Arya have to find the value x mod k. There are n ancient numbers c1, c2, ..., cn and Pari has to tell Arya x mod ci if Arya wants. Given k and the ancient values, tell us if Arya has a winning strategy independent of value of x or not. Formally, is it true that Arya can understand the value x mod k for any positive integer x?

Input
  The first line of the input contains two integers n and k (1 ≤ n,  k ≤ 1 000 000) — the number of ancient integers and value k that is chosen by Pari.
  The second line contains n integers c1, c2, ..., cn (1 ≤ ci ≤ 1 000 000).

Output
  Print "Yes" (without quotes) if Arya has a winning strategy independent of value of x, or "No" (without quotes) otherwise.
*/

#include "bits/stdc++.h"
using namespace std;

int lcm(int a, int b){
  return (a*b)/__gcd(a, b);
}

string solve(int n, int k, vector<int> c){
  int l = 1;
  for(auto &i: c){
    l = lcm(__gcd(i, k), l);
  }

  return l == k ? "Yes" : "No";  
}