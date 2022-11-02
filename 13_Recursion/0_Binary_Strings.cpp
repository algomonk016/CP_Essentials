/*
  Binary Strings
    Count the number of binary strings with no consecutive ones that can be formed using a binary string of length n.

  n -> 3
  valid
    000
    001
    010
    100
    101
  invalid:
    011
    110
    111
*/

int countBinaryStrings(int n){
  if(n <= 0) return 1;

  return countBinaryStrings(n-2) + countBinaryStrings(n-1);
}