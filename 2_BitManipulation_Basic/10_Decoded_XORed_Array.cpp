/*
Decode XORed Array
  There is a hidden integer array arr that consists of n non-negative integers.
  It was encoded into another integer array encoded of length n - 1, such that encoded[i] = arr[i] XOR arr[i + 1]. For example, if arr = [1,0,2,1], then encoded = [1,2,3].
  You are given the encoded array. You are also given an integer first, that is the first element of arr, i.e. arr[0].
  Return the original array arr. It can be proved that the answer exists and is unique.

Constraints:
  2 <= n <= 10^4
  encoded.length == n - 1
  0 <= encoded[i] <= 10^5
  0 <= first <= 10^5

Input: encoded = [1,2,3], first = 1
Output: [1,0,2,1]
*/ 

#include<bits/stdc++.h>
using namespace std;

vector<int> decode(vector<int> encoded, int first) {
  vector<int> decoded;
  decoded.emplace_back(first);
  for(auto &i: encoded){
    int x = i ^ decoded.back();
    decoded.emplace_back(x);
  }
  return decoded;
}