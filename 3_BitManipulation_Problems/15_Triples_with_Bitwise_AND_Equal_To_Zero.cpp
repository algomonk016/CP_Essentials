/*
Triples with Bitwise AND Equal To Zero

  Given an integer array nums, return the number of AND triples.
  An AND triple is a triple of indices (i, j, k) such that:
  0 <= i < nums.length
  0 <= j < nums.length
  0 <= k < nums.length

  nums[i] & nums[j] & nums[k] == 0, where & represents the bitwise-AND operator.

Constraints:
  1 <= nums.length <= 1000
  0 <= nums[i] < 2^16

Example :
  Input: nums = [2,1,3]
  Output: 12
*/ 

#include<bits/stdc++.h>
using namespace std;

int countTriplets(vector<int> a) {
    unordered_map<int, int> mp;
    
    int n = a.size();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            mp[a[i]&a[j]]++;
        }
    }
    
    int ans = 0;
    for(auto &i: a){
        for(auto &j: mp){
            auto [ad, freq] = j;
            
            if((ad & i) == 0){
                ans += freq;
            }
            
        }
    }
    
    return ans;
}