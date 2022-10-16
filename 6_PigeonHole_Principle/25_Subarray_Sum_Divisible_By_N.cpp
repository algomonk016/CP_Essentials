/*
Subarray Sum Divisible by N
  Given an integer array nums of size n , return the number of non-empty subarrays that have a sum divisible by n.
  A subarray is a contiguous part of an array.

Constraints:
  1 <= n <= 3 * 10^4
  0 <= nums[i] <= 10^4

Example:
  Input: n = 5, nums= [4, 5, 0, 4, 2]
  Output: 4
*/
#include "bits/stdc++.h"
using namespace std;

int solve(int n, vector<int> a){
  for(auto &i: a){
    cin>>i;
    i %= n;
  }
  vector<int> prefix(n, 0);
  prefix[0] = a[0];

  for(int i=1; i<n; i++){
    prefix[i] = prefix[i-1] + a[i];
  }

  int cnt = 0;
  for(auto &i: prefix){
    cnt += i%n == 0;
  }

  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      cnt += prefix[j] == prefix[i];
    }
  }

  return cnt;
}

int solve(int n, vector<int> a){
  unordered_map<int, int> mp;
  mp[0]++;
  int sum = 0;
  for(auto &i: a){
    sum += i;
    mp[sum%n]++;
  }

  int ans = 0;
  for(auto &i: mp){
    auto [mod, cnt] = i;
    ans += (cnt*(cnt-1))/2;
  }

  return ans;
}