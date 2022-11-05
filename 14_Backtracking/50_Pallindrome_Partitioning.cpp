/*
Pallindrome Partitioning: https://leetcode.com/problems/palindrome-partitioning/
  
  Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

  Input: s = "aab"
  Output: [["a","a","b"],["aa","b"]]
*/ 

#include "bits/stdc++.h"
using namespace std;

bool isPallindrome(string s){
  int i = 0, j = s.size()-1;
  while(i<j){
    if(s[i++] != s[j--]) return false;
  }
  return true;
}

void solve(string s, vector<string> &v, vector<vector<string>> &result){
  if(s == ""){
    result.push_back(v);
    return;
  }

  int n = s.size();
  for(int i=1; i<=n; i++){
    string curr = s.substr(0, i);
    if(isPallindrome(curr)){
      v.push_back(curr);
      solve(s.substr(i), v, result);
      v.pop_back();
    }
  }
}

vector<vector<string>> partition(string s) {
  vector<vector<string>> ans;
  vector<string> v;
  solve(s, v, ans);
  return ans;
}