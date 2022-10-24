/*
  Linear Diophantine Equations
    Polynomial equation in two or more unknowns, such that only integral solution are required.
    25x + 15y = 400

  Given 3 integers of the form ax + by = c.
  Determine the equation has a solution such that x and y are both integral solution.

  Approach:
    ax + by = c

    step 1: check solution exists or not
      let gcd(a, b) = g
      a = gk1
      b = gk2

      gk1x + gk2x = c
      k1x + k2y = c/g

      we need integral solution, LHS is int
      so, RHS must be int, i.e c % g should be 0

      solution exists if c%g is 0;
      k <- c/g

    step 2: find solution

      ax + by = kg
      x0, y0 is the solution for the equation

      ax0 + by0 = kg
      ax0 + by0 = k*gcd(a, b)     ... 1

      extended euclid eq
        ax + by = gcd(a, b)
        x' and y' are solution
        ax' + by' = gcd(a, b)     ... 2

        multiplying eq 2 by k
        k*ax'+ k* by' = k*gcd(a, b)


        hence,
        x0 = k*x'
        y0 = k*y'
*/

#include "bits/stdc++.h"
using namespace std;

vector<int> extendedGCD(int a, int b){
  if(b == 0){
    return {1, 0, a};
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
  /*ummeed hai ki base case ka socha hoga*/

  int a, b, c;
  cin>> a >> b >> c;

  vector<int> result  = extendedGCD(a, b);
  int x2 = result[0];
  int y2 = result[1];
  int g = result[2];

  if(c%g != 0){
    cout<<"No solution exists"<<endl;
    return;
  }

  int k = c/g;

  int x = x2 * k;
  int y = y2 * k;

  cout<<x<<" "<<y<<endl;
}
