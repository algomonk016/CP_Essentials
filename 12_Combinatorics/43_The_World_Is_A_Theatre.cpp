/* 
The world is a theatre: https://codeforces.com/problemset/problem/131/C 
  There are n boys and m girls attending a theatre club. 
  To set a play "The Big Bang Theory", they need to choose a group containing exactly t actors containing no less than 4 boys and no less than 1 girl. 
  How many ways are there to choose a group? Of course, the variants that only differ in the composition of the troupe are considered different.

Constraints:
  4 <= n <= 30
  1 <= m <= 30
  5 <= t <= n+m

Example:
  Input: n= 5, m= 2, t= 5
  Output: 10

  Simple brute force solution will work here
*/

#include<bits/stdc++.h>
using namespace std;

long long solve(int n, int m, int t){
  if(n + m == t){
    return 1;
  }

  int mx = 31;
  vector<vector<long long int>> nCr(mx+1, vector<long long int> (mx+1, 1));

  for(int i=1; i<=mx; i++){
    for(int j=1; j<i; j++){
      nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
    }
  }

  long long int ans = 0;

  for(int i=4; i<=n; i++){
    int girls = t-i;
    if(girls <= 0 or girls > m) continue;

    ans += nCr[n][i] * nCr[m][girls];
  }

  return ans;
} 

