/* 
Given two integers 'a' and 'm', find modular multiplicative inverse of 'a' under modulo 'm'.
The modular multiplicative inverse is an integer 'x' such that,

a*x is congruent to 1 mod m
ex, a = 6, m = 7

brute force
6*1 mod 7 != 1
6*2 mod 7 != 1
6*3 mod 7 != 1
6*4 mod 7 != 1
6*5 mod 7 != 1
6*6 mod 7 == 1, hence x = 6

extended euclids algo,
  ax + by = gcd(a, b)
  ax + my = gcd(a, m)  --> gcd given in the question

  ax + my = 1
  ax%m + my%m = 1%m
  ax%m + 0 = 1
  ax % m = 1
  ax = 1(mod m)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> extendedGCD(int a, int b){
  if(b == 0){
    return { 1, 0, a};
  }

  vector<int> result = extendedGCD(b, a%b);

  int currentX = result[0];
  int currentY = result[1];
  int gcd = result[2];

  int x = currentY;
  int y = currentX - (a/b)*x;

  return {x, y, gcd};
}


void solve(int testCase) {
  int a, m;
  cin>>a>>m;

  vector<int> moduloInverse = extendedGCD(a, m);

  int x = moduloInverse[0];
  int gcd = moduloInverse[2];

  if(gcd != 1){
    cout<<"Modulo inverse doesn't exist"<<endl;
    return;
  }

  x = (x%m+m)%m;

  cout<<x<<endl;
}
