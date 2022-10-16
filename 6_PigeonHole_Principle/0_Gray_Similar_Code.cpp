/*
Gray Similar Code: https://www.codechef.com/problems/GRAYSC

provided: 
  - 64 bit numbers (use unsigned long long int)
  - padosi numbers differ at only 1 bit
  - to check whether we have 4 numbers such that their xor is 0

approach:
  a[i]: 110010
  a[i+1]: 110110
  a[i] ^ a[i+1]: 000100

  i.e when two consecutive numbers will be XORed, then only one bit will be one
  so numbers of different set bits: 64 (coz 64 bit numbers)
  if there are 65 or more pairs, then we can apply pigeonhole principle and conclude that there will be some i, where more than 1 numbers have set bit
  that means, for >=65 pairs (n >= 130), ans is YES

  for n < 130, do brute force
*/ 

#include "bits/stdc++.h"
using namespace std;
#define int unsigned long long int

void solve(int n, vector<int> a){
  if(n >= 130){
    cout<<"Yes"<<endl;
    return;
  }
  unordered_set<int> st;
  st.insert(a[0]);

  for(int i=1; i<n; i++){
    for(int j=i+1; j<n; j++){
      for(int k=j+1; k<n; k++){
        int d = a[i]^a[j]^a[k];
        if(st.find(d) != st.end()){
          cout<<"Yes"<<endl;
          return;
        }
      }
    }
    st.insert(a[i]);
  }

  cout<<"No"<<endl;
}

signed main(){
  int n;
  cin>>n;

  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin>>a[i];
  }

  solve(n, a);

  return 0;
}
