/*
Prime Sum
  You are given a number n. Find all the pairs (l, r) such that l <= r and their sum is also prime and no more than n.
  Note: l and r should be prime too.

Constraints:
  1 <= n <= 10^5

Example:
  Input: n= 5
  Output: 1
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    vector<int>prime(n+1,1);
    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
    int ans=0;
    for(int i=3;i<=n-2;i++){
        if(prime[i]==1 && prime[i+2]==1){
            ans++;
        }
    }
    return ans;
}
