/*
Friend's Pairing Problem
  Given N friends who want to go to party, each one can remain single or can be paired with some other friend.
  Each friend can be paired only once.
  Find out total number of ways each friend can remain single or can be paired. 

  Example:
    3 friends
    ABC
    A B C
    AB C
    AC B
    A BC

    So, if he is going alone,
    number of ways = f(n-1)

    if he is making pair, no of ways
      (n-1)C1 * f(n-2)
*/

int findWays(int n){
  if(n <= 1) return 1;
  return findWays(n-1) + (n-1) * findWays(n-2);
}