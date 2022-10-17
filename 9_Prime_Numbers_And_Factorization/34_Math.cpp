/*
Math: https://codeforces.com/problemset/problem/1062/B
  Given an integer n, you can perform the following operations zero or more times:
  mul x: multiplies n by x (where x is an arbitrary positive integer).
  sqrt: replaces n with √n (to apply this operation, √n must be an integer).

  You can perform these operations as many times as you like. What is the minimum value of n, that can be achieved, and what is the minimum number of operations, to achieve that minimum value?
  Return an array containing the minimum value of n and the number of operations required to achieve that value respectively.

Constraints:
1 <= n <= 10^6

Approach: 
  By factorizing 𝑛 we get 𝑛=𝑝1𝑎1𝑝2𝑎2…𝑝𝑘𝑎𝑘 (𝑘 is the number of prime factors). 
  Because we can't get rid of those prime factors then the smallest 𝑛 is 𝑝1𝑝2…𝑝𝑘. 
  For each 𝑎𝑖, let 𝑢𝑖 be the positive integer so that 2𝑢𝑖≥𝑎𝑖>2𝑢𝑖−1. 
  Let 𝑈 be 𝑚𝑎𝑥(𝑢𝑖). It's clear that we have to apply the "𝑠𝑞𝑟𝑡" operation at least 𝑈 times, since each time we apply it, 𝑎𝑖 is divided by 2 for all 𝑖.
  If for all 𝑖, 𝑎𝑖=2𝑈 then the answer is 𝑈, obviously. Otherwise, we need to use the operation "𝑚𝑢𝑙" 1 time to make all the 𝑎𝑖 equal 2𝑈 and by now the answer is 𝑈+1.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int n){
  map<int, int> primes;

  for(int i=2; i*i <= n; i++){
    while(n%i == 0){
      primes[i]++;
      n/=i;
    }
  }

  if(n>1){
    primes[n]++;
  }

  int value = 1, x = 0;
  for(auto &i: primes){
    auto [prime, cnt] = i;
    x = max(x, (int)ceil(log2(cnt)));
    value *= prime;
  }

  int cnt = 0;
  int val = (1 << x);
  for(auto &i: primes){
    cnt += val - i.second;
  }

  if(cnt){
    x++;
  }

  vector<int> v = {value, x};
  return v;
}