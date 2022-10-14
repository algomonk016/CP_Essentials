/*
POW
  For a base number X, the product of multiplying it Y times is called X to the Y-th power and represented as pow(X,Y). For example, we have pow(2,3)=2×2×2=8.
  Given three integers A, B, and C, compare pow(A,C) and pow(B,C) to determine which is greater.
  If pow(A,C)<pow(B,C), return <; if pow(A,C)>pow(B,C), return >; if pow(A,C)=pow(B,C), return = .

Constraints:
  -10^9 <= A, B <= 10^9
  1<= C <= 10^9

Example 1:
  Input
  A = 3,  B = 2 , C = 4
  Output
  ">"
*/ 
#include<bits/stdc++.h>
using namespace std;

string solve(int A,int B, int C){
  int sign1=(A<0 && C%2);
  int sign2=(B<0 && C%2);
  string ans;
  if(sign1!=sign2){
    ans=sign1? "<": ">";
  }
  else{
    if(abs(A)==abs(B)){
      ans="=";
    }
    else if((abs(A)<abs(B)) ^ sign1){
      ans="<";
    }
    else{
      ans=">";
    }
  }
  return ans;
}