#include <bits/stdc++.h>
using namespace std;

int uniqueNumber(vector<int> a){
  int num = 0;
  for(auto &i: a){
    num ^= i;
  }
  return num;
}

/* find the two non repeating numbers */ 
/* suppose: a -> 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7
  * xor -> 5^7
  * 101 ^ 111 -> 010
  * 
  * so, from output we can conclude that, atleast one bit will be set in xor
  * 
  * find that position
  *
  * approach: 
  *  iterate over array, take xor of all numbers that has same set bit
  **/ 
vector<int> uniqueNumber2(vector<int> a){
  int xo = 0;
  for(auto &i: a){
    xo ^= i;
  }

  int pos = 0;
  int ixo = xo;
  while((xo&1) == 0){
    pos++;
    xo >>= 1;
  }

  int mask = (1 << pos);
  int setA = 0, setB = 0;
  for(auto &i: a){
    if(mask & i){
      setA ^= i;
    } else{
      setB ^= i;
    }
  }

  vector<int> ans;
  ans.emplace_back(setA);
  ans.emplace_back(setB);
  return ans;
}

/* find the one unique number, rest numbers are repeating thrice */ 
/*
 * 5, 5, 5, 4, 4, 4, 7
 * 5 -> 101
 * 7 -> 111
 * 4 -> 100
 *
 * cnt -> { 7, 3, 6 }
 *
 * we can observe the count will be 3*n or 3*n + 1,
 * 3*n + 1 -> jahan unique number set hai
 */
int uniqueNumber3(vector<int> a){
  vector<int> cnt(32, 0);

  for(auto &i: a){
    int num = i;
    int pos = 0;
    while(num){
      cnt[pos] += num&1;
      num >>= 1;
      pos++;
    }
  }

  int num = 0;
  for(int i=0; i<32; i++){
    if(cnt[i]%3){
      int mask = (1 << i);
      num |= mask;
    }
  }

  return num;
}

/* print all subsets of string */ 
/*
  s: abc
  n: 3
  no of subsets: pow(2, n) - 1
  0 000 -> ""
  1 001 -> a
  2 010 -> b
  3 011 -> ab
  4 100 -> c
  5 101 -> ac
  6 110 -> cb
  7 111 -> abc
*/ 
void printSubsets(string s){
  int n = s.length();
  int noOfSubsets = (1 << n);

  string subset;
  cout<<"{ ";
  for(int i=0; i<noOfSubsets; i++){
    subset = "";

    int pos = 0;
    int x = i;
    while(x){
      int doInclude = x&1;
      if(doInclude)
        subset += s[pos];

      x >>= 1;
      pos++;
    }

    cout<<"\""<<subset<<"\""<<" ";
  }

  cout<<"}";

}
