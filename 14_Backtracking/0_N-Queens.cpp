/*
N-Queens
  N queen is the problem of placing N chess queens on a chessboard of N*N
  such that no two queens can attack each other.

  N = 4
  0 1 0 0
  0 0 0 1
  1 0 0 1
  0 0 1 0

  here 1 denotes position of Queens
*/
#include "bits/stdc++.h"
using namespace std;

int n;
int arr[10][10];

bool check(int i, int j){
  int ii = i, jj = j;

  while(ii--){
    if(arr[ii][j]) return false;
  }

  ii = i;
  while(ii-- && jj--){
    if(arr[ii][jj]) return false;
  }

  ii = i, jj = j;
  while(ii-- && jj++ < n){
    if(arr[ii][jj]) return false;
  }

  return true;
}

bool nQueen(int i){
  if(i == n){
    cout<<"New way\n";
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cout<<arr[i][j]<<" ";
      }
      cout<<endl;
    }

    return true;
  }

  int flag = 0;
  for(int j=0; j<n; j++){
    if(check(i, j)){
      arr[i][j] = 1;
      flag = nQueen(i+1); 

      // for 1 way
      // if(!flag){
      //   arr[i][j] = 0;
      // }

      // for all ways
      arr[i][j] = 0;
    }
  }

  return flag;
}
