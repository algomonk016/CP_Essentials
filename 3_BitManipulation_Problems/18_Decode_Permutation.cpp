/*
Decode Permutation
  There is an integer array perm that is a permutation of the first n positive integers, where n is always odd.
  It was encoded into another integer array encoded of length n - 1, such that encoded[i] = perm[i] XOR perm[i + 1]. For example, if perm = [1,3,2], then encoded = [2,1].
  Given the encoded array, return the original array perm. It is guaranteed that the answer exists and is unique.

Constraints:
  3 <= n < 10^5
  n is odd.
  encoded.length == n - 1

Example :
  Input: encoded = [3,1]
  Output: [1,2,3]

  Input: encoded = [6,5,4,6]
  Output: [2,4,1,5,3]

logic:
  we'll firstly find the first number of actual array
  then using that, we'll retrieve the whole array
  e[0] = a[0]^a[1]
  e[1] = a[1]^a[2]
  e[2] = a[2]^a[3]
  a[3] = a[3]^a[4]

  so, e[1]^e[3] =  a[1]^a[2]^a[3]^a[4], only a[0] will be missing here
  if we've used e[0]^e[2] <- a[0]^a[1]^a[2]^a[3], we should've got a[4], i.e the last num, we can use that too.
  but in this approach, we are going with e[1]^a[3]

  so, in that xor, to cancel out the rest ones, we will xor it with totalXOR,
  that is nothing but xor of 1 to n+1 (n is size of encoded array)
  so, all the elements will cancel out each other, except a[0], that's what we wanted

  now, we'll use a[0] to get our actual array.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> decode(vector<int> v) {
  int n = v.size();
  int totalXor = 0;
  for(int i=1; i<=n+1; i++){
    totalXor ^= i;
  }

  int x = 0;
  for(int i=1; i<n; i+=2){
    x ^= v[i];
  }

  int fst = totalXor ^ x;

  vector<int> ans;
  ans.emplace_back(fst);
  for(auto &i: v){
    fst = ans.back() ^ i;
    ans.emplace_back(fst);
  }

  return ans;
}