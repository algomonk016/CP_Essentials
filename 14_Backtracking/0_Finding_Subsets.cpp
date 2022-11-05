/*
Finding Subsets
  Given a string, find all subsets of the string
  Ex: ABC
  "", "A", "B", "C", "AB", "AC", "ABC", "BC"
*/

#include "bits/stdc++.h"
using namespace std;

void findSubsets(string s, string output, int i, int n){
  if(i == n) {
    cout<<output<<endl;
    return;
  }

  findSubsets(s, output + s[i], i+1, n);
  findSubsets(s, output, i+1, n);
}

void solve(int testCase) {
  int n;
  string s;
  cin>>n>>s;

  findSubsets(s, "", 0, n);
}