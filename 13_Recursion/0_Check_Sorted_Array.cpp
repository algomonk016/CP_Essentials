#include "bits/stdc++.h"
using namespace std;

// initial function call: (array, 0, arraySize)
int isSorted(vector<int> a, int ind, int n){
  if(ind + 1 == n){
    return 1;
  }

  return (a[ind] < a[ind+1]) && isSorted(a, ind+1, n);
}