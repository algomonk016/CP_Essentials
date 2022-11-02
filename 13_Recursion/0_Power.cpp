/*  
  Recursive Program to calculate a raised to power b
*/

/*
  Naive approach
  Time: O(b)
*/ 
int power(int a, int b){
  if(b == 0) return 1;
  if(b == 1) return a;
  return a * power(a, b-1);
}

/*
  Binary Exponentiation
  Time: O(log b)
*/ 
int fastPower(int a, int b){
  if(b == 0) return 1;
  if(b == 1) return a;

  int current = 1;
  if(b & 1) current *= a;
  a = a*a;

  return current * fastPower(a, b >> 1);
}
