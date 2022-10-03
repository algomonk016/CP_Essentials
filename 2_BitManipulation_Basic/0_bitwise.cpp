#include<bits/stdc++.h>
using namespace std;

int getIthBit(int n, int i){
  int mask = (1 << i);
  return (n & mask ? 1 : 0);
}

void clearIthBit(int &n, int i){
  int mask = ~(1 << i);
  n &= mask;
}

void setIthBit(int &n, int i){
  int mask = (1 << i);
  n |= mask;
}

void updateIthBit(int &n, int i, int value){
  clearIthBit(n, i);
  int mask = (value << 1);
  n |= mask;
}

void clearLastIBits(int &n, int i){
  int mask = (-1 << i);
  n &= mask;
}

void clearBitsInRange(int &n, int i, int j){
  int a = (-1 << j+1);
  int b = (1 << i) - 1;
  int mask = a | b;

  n &= mask;
}

void replaceBitsInNByM(int &n, int m, int i, int j){
  clearBitsInRange(n, i, j);

  int mask = m << i;

  n |= mask;
}

int cntSetBits(int n){
  int cnt = 0;
  while(n){
    cnt += n&1;
    n>>=1;
  }
  return cnt;
}

int cntSetBitsFast(int n){
  int cnt = 0;
  while(n){
    n &= (n-1);
    cnt++;
  }

  return cnt;
}

int decimalToBinary(int n){
  int num = 0;
  int p = 1;
  while(n){
    int last = n & 1;
    num += last*p;
    n >>= 1;
    p *= 10;
  }

  return num;
}
