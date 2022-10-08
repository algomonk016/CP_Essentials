#include<bits/stdc++.h>
using namespace std;

int matrixScore(vector<vector<int>> grid) {
  int maxScore = 0;
  int n = grid.size(), m = grid[0].size();

  for(int i=0; i<n; i++){
    if(grid[i][0] == 0){
      for(int j=0; j<m; j++){
        grid[i][j] ^= 1;
      }
    }
  }

  for(int j = 0; j<m; j++){
    int cnt = 0;
    for(int i=0; i<n; i++){
      cnt += grid[i][j];
    }

    maxScore += max(cnt, n-cnt) * (1 << (m-j-1));
  }
  
  return maxScore;   
}    