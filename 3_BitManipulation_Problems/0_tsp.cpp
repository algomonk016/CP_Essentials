#include <bits/stdc++.h>
using namespace std;

int tsp (vector<vector<int>> dist, int setOfCities, int city, int n, vector<vector<int>> dp){
  // base case, all cities visited
  if(setOfCities == (1<<n)-1){
    return dist[city][0];
  }

  if(dp[setOfCities][city] != -1){
    return dp[setOfCities][city];
  }

  int ans = INT_MAX;

  for(int i=0; i<n; i++){
    int mask = (1 << i);
    if((setOfCities & mask) == 0){
      int subPrblm = dist[city][i] + tsp(dist, (setOfCities | mask), i, n, dp);
      ans = min(ans, subPrblm);
    }
  }

  dp[setOfCities][city] = ans;
  return ans;
}

int main(){
  vector<vector<int>> v = {
    { 0, 20, 42, 25 },
    { 20, 0, 30, 34 },
    { 42, 30, 0, 10 },
    { 25, 34, 10, 0 }
  };

  int n = v.size();

  vector<vector<int>> dp(1<<n, vector<int> (-1));

  // setOfCities inititally 0001, ind: 0, total: 4
  cout<<tsp(v, 1, 0, 4, dp)<<endl;

  return 0;
}