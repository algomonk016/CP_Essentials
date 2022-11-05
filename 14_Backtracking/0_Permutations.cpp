/*
Permutations
  Given a string s
  find all permutations of the string
*/
#include "bits/stdc++.h"
using namespace std;

// permute(s, 0, n-1)
void permute(string &s, int l, int r){
  if(l == r){
    cout<<s<<endl;
    return;
  }

  for(int i = l; i<=r; i++){
    swap(s[l], s[i]);
    permute(s, l+1, r);
    swap(s[l], s[i]);
  }
}
