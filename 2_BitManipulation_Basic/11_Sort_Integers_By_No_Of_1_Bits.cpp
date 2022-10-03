/*
Sort Integers by The Number of 1 Bits
  Given an integer array arr. You have to sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.
  Return the sorted array.

Constraints:
  1 <= arr.length <= 500
  0 <= arr[i] <= 10^4

Example :
  Input: arr = [0,1,2,3,4,5,6,7,8]
  Output: [0,1,2,4,8,3,5,6,7]
*/ 

#include<bits/stdc++.h>
using namespace std;

int cntSetBitsFast(int n){
  int cnt = 0;
  while(n){
    n &= (n-1);
    cnt++;
  }

  return cnt;
}

bool compare(const int a, const int b){
  int bitsA = cntSetBitsFast(a), bitsB = cntSetBitsFast(b);
  if(bitsA == bitsB){
    return a < b;
  }
  return  bitsA < bitsB;
}

vector<int> sortByBits(vector<int> a) {
  sort(a.begin(), a.end(), compare);
  return a;
}