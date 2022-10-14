/*
Strange Function
  As New Year is approaching, Salik is studying functions in order to sharpen his math skills. Instead of regular functions, he is studying a strange function F which operates on non-negative integers. The value of F(A) is obtained by the following process:
  Compute the sum of digits of A; let's denote this sum by S.
  If S is a single-digit integer, then F(A) = S.
  Otherwise, F(A) = F(S).
  It's guaranteed that this process correctly defines the function F.
  Since this problem was pretty straightforward, he invented a new problem: Given two integers A and N, compute F(A^N).
  Return the value of F(A^N).

Constraints:
  1<= N, A <= 10^18

Example:
  Input: A = 7 , N = 2 
  Output: 4

approach, mod pow with 9, coz we just need the last digit
*/

long long int power9(long long a, long long n){
  long long p;

  if(n == 0){
    return 1;
  }

  p = power9(a, n>>1);
  p = (p*p)%9;

  if(n&1){
    p = (p*a)%9;
  }

  return p;

}

int solve(long long a, long long b){
  int p = power9(a, b);

  if(!p){
    return 9;
  }

  return p;
}
