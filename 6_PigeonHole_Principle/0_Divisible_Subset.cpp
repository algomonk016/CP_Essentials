/*
Divisible Subset: https://www.codechef.com/problems/DIVSUBS

n: 5
a: [1 2 3 6 7]
p: [1 3 6 12 19]

we need 
  (prefix[i] - prefix[j])%n = 0
  prefix[i]%n = prefix[j]%n

so, take mod of prefix
a: [1 2 3 6 7]
p: [1 3 1 2 4]

if we get any 0 in the prefix, that means we have our ansr, 1 to indexOf(0)

else, 
  number of possible value: n-1, i.e 1 to n-1
  numbers: n
  so, applying pigeonhole principle, we can conclude that, atleast 1 prefix%n will repeat,
  that means, diff b/w the numbers is multiple of n
  in given example, ind 1 & 3 have same value after mod, i.e index 2 & 3 are the ansrs
*/ 

#include <bits/stdc++.h>
using namespace std;
#define br "\n"

void code(int n, vector<int> a){
  vector<int> preSum(n, 0);
  unordered_map<int, int> mp; // for storing index of preSum%n
  preSum[0] = a[0];

  for(int i=1; i<n; i++){
    if(a[i]%n == 0){
      cout<<1<<br;
      cout<<i+1<<br;
      return;
    }
    preSum[i] = preSum[i-1] + a[i];
  }

  int ind = 0;
  for(auto &i: preSum){
    i %= n;
    if(i == 0){
      cout<<ind+1<<br;
      for(int j=1; j<=ind+1; j++){
        cout<<j<<" ";
      }
      cout<<br;
      return;
    }

    if(mp.find(i)!=mp.end()){
      int first = mp[i];
      int second = ind;

      cout<<second-first<<br;
      for(int j = first+2; j<second+2; j++){
        cout<<j<<" ";
      }
      cout<<br;
      return;
    } else{
      mp[i] = ind;
    }

    ind++;
  }

  cout<<"-1"<<br;
}