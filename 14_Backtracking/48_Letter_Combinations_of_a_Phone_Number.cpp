/*
Letter Combinations of a phone number: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Make sure the returned strings are lexicographically sorted.

Constraints:
  0 <= digits.length <= 4
  digits[i] is a digit in the range ['2', '9'].

Example :
  Input: digits = "23"
  Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/ 

#include<bits/stdc++.h>
using namespace std;

map<char, string> mp;

void pre(){
  mp['2'] = "abc";
  mp['3'] = "def";
  mp['4'] = "ghi";
  mp['5'] = "jkl";
  mp['6'] = "mno";
  mp['7'] = "pqrs";
  mp['8'] = "tuv";
  mp['9'] = "wxyz";
}

void f(int i, string s, int n, string current, vector<string> &res){
  string si = mp[s[i]];
  int nsi = si.length();

  for(int j=0; j<nsi; j++){
    if(i == n-1){
      res.push_back(current + si[j]);
    } else{
      f(i+1, s, n, current + si[j], res);
    }
  }
}

vector<string> letterCombinations(string s){
  pre();
  int n = s.length();

  vector<string> res;
  f(0, s, n, "", res);
  
  sort(res.begin(), res.end());
  
  return res;
}
