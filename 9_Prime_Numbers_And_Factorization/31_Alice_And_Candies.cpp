/* 
https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/lola-and-candies-36b57b1b/ 

as we know,
  sum of first N odd numbers = N^2
  for consecutive numbers sum to be equal to N,
  1, 3, 5, .. a, ... b.
  b^2 - a^2 = n;
  (b+a)(b-a) = n

  b+a = x;
  b-a = y;
  2*b = x+y
  i.e, b = (x+y)/2

  if (x+y) is even, then we can increment ans
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int n){
  int candies = 0;

  for(int i=1; i*i <= n; i++){
    if(n%i == 0){
      int x = i;
      int y = n/i;

      candies += !((x+y)&1);
    }
  }

  return candies;
}