/*
SIG -> SIGMA

  Expected Heads
  A fair coin is thrown N times, what is the expected number of Heads.

  P(H) = 0.5

  z = {e1, e2, e3, e4, ..., en}
  e(z) = e{e1, e2, e3, e4, ..., en}
       = e(e1) + e(e2) + e(e3) + ... + e(en)
       = SIG 1 to n (0.5)
       = n/2

  e[ei] = SIG xi.pxi = 1(1/2) + 0(1/2)
        = 0.5

  ans = n/2
*/

/*
  What is expected number of coin flips to get a head?

    x = SIG xi.p(xi)
    x = turn * chance of getting HEAD + (turns)*(chance of not getting head)
    x = 1*(1/2) + (1+x)*(1/2)
    2x = 1 + 1 + x
    x = 2

    suppose, first turn pe tail aa gaya, then we need x turns to get head, that's why (1 + x)
*/ 

/*
  What is the expected number of coin flips to get two CONSECUTIVE HEADS?

    x = 1/2 * 1/2 * (2) + 1/2 * 1/2 * (x+2) + 1/2 * (x+1)
    x = 1/2 + (x+2)/4 + (x+1)/2
    x = 6

    HH -> 1/2 * 1/2 * (2 turns)
    HT -> 1/2 * 1/2 * (2 turns wasted + x more turns to get result)
    T -> 1/2 * (1 turn wasted + x more turns to get result)
*/ 

/*
  What is the expected number of coin flips to get N CONSECUTIVE HEADS?
    x = (1/2 * (x + 1)) + (1/2 * 1/2 * (x+2)) + (1/2 * 1/2 * 1/2 * (x+3)) + ... + 1/pow(2, n) * (x+n) + 1/pow(2, n) * (n)
    x = 1/pow(2, 1) * (x + 1) + (1/pow(2, 2) * (x + 2)) + (1/pow(2, 3) * (x + 3)) + ... + (1/pow(2, n) * (x+n)) + (1/pow(2, n) * (n))
    x = x(1/2 + 1/4 + 1/8 + ... + 1/pow(2, n)) + 1/2 + 2/4 + 3/8 + ... + n/pow(2, n) + n/pow(2, n)
          ----- GP -----                             --- AGP ----      

    x = pow(2, n+1) - 2

    HHHHH... -> 1/2 * 1/2 * ...n times * (N turns) -> 1/pow(2, n) * (N)
    HHHHT -> 1/2 * 1/2 * 1/2 * ... n-1 times * (N turns wasted + X more turns to get result) --> 1/pow(2, n-1) * (N + x)
    HHHT -> 1/2 * 1/2 * 1/2 * ... n-2 times * (N-1 turns wasted + X more turns to get result) --> 1/pow(2, n-2) * (N-1 + x)
    ...
    T -> 1/2 * (1 turn wasted + X more turns to get result) --> 1/2 * (1 + x)

*/ 