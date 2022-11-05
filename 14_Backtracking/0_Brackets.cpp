/*
Brackets
  Write a function to generate all n pairs of vaild brackets

  ex: 
  n = 2
  ()()
  (())
*/

#include "bits/stdc++.h"
using namespace std;

// brackets(n, 0, 0, "")
void brackets(int n, int open, int close, string output){

  if(n == open){
    int rem = n - close;
    while(rem--){
      output += ')';
    }

    cout<<output<<endl;
    return;
  }

  if(close < open){
    brackets(n, open, close+1, output + ")");
  }

  brackets(n, open+1, close, output + "(");
}

