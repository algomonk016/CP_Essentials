/*
Factorial of a Number
f(n) = n * n-1 * n-2 * .. * 1
f(n) = n * f(n-1)
*/ 

// time: O(n), auxiliary space: O(n)
int factorial(int n){
  if(n <= 1){
    return 1;
  }

  return n * factorial(n-1);
}
