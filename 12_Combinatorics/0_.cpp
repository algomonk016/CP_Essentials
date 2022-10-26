/*
Combinatorics
  Combinations: no of ways of choosing r distinct objects 
    nCr
  Permutation: no of ways of arranging r distinct objects
    nPr

  Given 5 persons, no of ways to select 1 captain.
    5C1 -> 5!/4!-1! = 5

  Select 2 persons
    5C2 -> 10

  Select two persons, one for captain, one for co-captain
    Captain, Cocaptains
    A , 4
    B , 4
    C , 4
    D , 4
    E , 4

    i.e pick persons * arrange
    5C2 * 2! = 10 * 2 = 20
    nPr = n!/(n-r)! = 5! / 3! = 20s

Basic Combinatorics Rule
  given 5 boys and 7 girls

  Rule of product:
    Select 3 boys AND 2 girls
    5C3 * 7C2
  
  Rule of sum:
    Select 3 boys OR 2 girls
    5C3 + 7C2

*/

/*
Permutations with repetition

If we have N objects out of which N1 objects are of type 1, N2 objects are of type 2, ... Nk objects are of type k, then number of ways of arrangement of these N objects are given by:
N! / N1! N2! N3! ... Nk!

Combinations with repetition:

If we have N elements out of which we want to choose K elements and it is allowed to choose one element more than once, then number of ways are given by:
n+k-1Ck = (n+k-1)!/(n-1)! * k!
*/ 