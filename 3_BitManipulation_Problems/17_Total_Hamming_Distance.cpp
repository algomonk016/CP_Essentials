/*
Total Hamming Distance
  The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
  Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.

Constraints:
  1 <= nums.length <= 10^4
  0 <= nums[i] <= 10^9

The answer for the given input will fit in a 32-bit integer.

Example 1:
  Input: nums = [4,14,2]
  Output: 6

4 14 2
10 -> 2
100 -> 
1110
*/

#include<bits/stdc++.h>
using namespace std;

// brute force, calculate by O(n^2)
int getDist(int n, int m){
  int ans = 0;
  while(1){
    if(!n && !m){
      break;
    }
    ans += (n&1) != (m&1);
    m >>= 1;
    n >>= 1;
  }
  return ans;
}

int totalHammingDistance(vector<int> nums) {
  int ans = 0;
  int n = nums.size();
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      int dist = getDist(nums[i], nums[j]);
      ans += dist;
    }
  }
  
  return ans;
}

/*
Optimized approach
  count number of zeroes & ones for each bit,
  say, arr: [2, 4, 14]
  i -> 0, zeroes: 0, ones: 0
  i -> 1, zeroes: 1, ones: 2, distance: 2*1
  i -> 2, zeroes: 1, ones: 2, distance: 2*1
  i -> 3, zeroes: 2, ones: 1, distance: 2*1

  total distance: 6
*/ 

int totalHammingDistance(vector<int> nums) {
  int ans = 0;
  int zeroes, ones;
  for(int i=0; i<31; i++){
    int mask = (1 << i);
    zeroes = 0, ones = 0;
    for(auto &j: nums){
      if(j&mask){
        ones++;
      } else{
        zeroes++;
      }
    }
    ans += ones*zeroes;
  }
  
  return ans;
}