/*
Decreasing Sequence
  You are given two integers L and R. Find the smallest non-negative integer N such that
  N%L > N%(L+1) > … > N%(R−1) > N%R.
  Here, % is the modulo operator, so A%B is the remainder of A after division by B. For example, 11%3=2.
  Return the smallest possible N if solution exists otherwise return -1.

Constraints:
  1 <= L < R <= 10^8

Example 1:
  Input: L= 4 , R= 6
  Output: 6
*/

int solve(int L, int R){
  if (R - L +1 >L)
    return -1;
  return R;
}