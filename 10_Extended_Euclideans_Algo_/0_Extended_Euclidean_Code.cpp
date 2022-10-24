#include <bits/stdc++.h>
using namespace std;

// Ax + By = gcd(A, B)
// returns vector of size 3, {x, y, gcd}
vector<int> extendedGCD(int a, int b){
  if(b == 0){
    return {1, 0, a};
  }

  vector<int> result = extendedGCD(b, a%b);

  //bottom up
  int smallX = result[0];
  int smallY = result[1];
  int gcd = result[2];

  int x = smallY;
  int y = smallX - (a/b)*smallY;

  return {x, y, gcd};
}