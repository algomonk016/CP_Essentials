/*
Bob and Impossible Calculation: https://codeforces.com/problemset/problem/1305/C
To become the king of CP, Bob has to solve the following problem.

PIE 1<=i<j<=n |ai - aj|
In other words, this is the product of |ai−aj| for all 1≤i<j≤n.
He is given n numbers a1,a2,…,an. Help Bob to calculate:
As the result can be very big, return it modulo m.

Constraints:
  2 <= n <= 10^5
  1 <= m <= 1000
  0 <= ai <= 10^9

Example:
  Input: n = 2, m = 10, a = [8, 5]
  Output: 3


*/

#include<bits/stdc++.h>
using namespace std;

int p;
int mul(int a, int b) {
  return (1LL * a * b) % p;
}

int sub(int a, int b) {
  int s = (a+p-b);
  if (s>=p) s-=p;
  return s;
}

int solve(int n, int m, vector<int> a){
  p = m;
  if(n > m){
    return 0;
  }
  int ans = 1;
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      ans = mul(ans, abs(a[i]-a[j])%p);
    }
  }
  return ans;
}

