/*
Target Sum: https://leetcode.com/problems/target-sum/description/

  You are given an integer array nums and an integer target.

  You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

  For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
  Return the number of different expressions that you can build, which evaluates to target.

Input: nums = [1,1,1,1,1], target = 3
Output: 5
*/ 
#include "bits/stdc++.h"
using namespace std;

int ans;
void f(int i, vector<int> &a, int n, int sum, char op, int target){
    // if(i == n) return;
  if(i == n-1){
    if(sum + (op == '+' ? a[i] : -a[i]) == target){
      ans++;
    }
    return;
  }

  f(i+1, a, n, sum + (op == '+' ? a[i] : -a[i]), '+', target);
  f(i+1, a, n, sum + (op == '+' ? a[i] : -a[i]), '-', target);
}

int findTargetSumWays(vector<int> &a, int target){
  ans = 0;
  int n = a.size();
  if(n == 0) return 0;

  f(0, a, n, 0, '+', target);
  f(0, a, n, 0, '-', target);

  return ans;
}