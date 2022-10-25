/*
Good Array: https://leetcode.com/problems/check-if-it-is-a-good-array/
  Given an array nums of positive integers. Your task is to select some subset of nums, multiply each element by an integer and add all these numbers. The array is said to be good if you can obtain a sum of 1 from the array by any possible subset and multiplicand.
  Return True if the array is good otherwise return False.

Constraints:
  1 <= nums.length <= 10^5
  1 <= nums[i] <= 10^9

Example :
  Input: nums = [12,5,7,23]
  Output: true
 
  Explanation: Pick numbers 5 and 7.
  5*3 + 7*(-2) = 1

Solution: if any subset has gcd 1, then true, else false
*/

#include<bits/stdc++.h>
using namespace std;

bool isGoodArray(vector<int> nums){
  int gcd = nums[0];
  int n = nums.size();
  for(int i=1; i<n; i++){
    gcd = __gcd(gcd, nums[i]); 
  }
  return gcd == 1;
}

