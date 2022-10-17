/*
  intersection: ∩
  union: ∪
  A∪B = A + B - A∩B

  A∪B∪C = A + B + C + A∩B∩C - A∩B - A∩C - B∩C

  A∪B∪C∪D = A + B + C + D - A∩B - A∩C - A∩D - B∩C - B∩D - C∩D + A∩B∩C + A∩B∩D + B∩C∩D + A∩C∩D - A∩B∩C∩D
  No of elements = 4c1 - 4c2 + 4c3 - 4c4
                 = 2^n - 1

  Pattern in this
    - we add ODD
    - subtract EVEN

*/

/*
Total numbers of permutations of 0-9, which contains 13, 49, 34, 25

total --> 10!
Permutations Count -> p13 + p49 + p34 + p25 
                    - p13,34 - p13,49 - p13,25 - p49,34 - p49,25 - p34,25
                    + p13,34,49 + p13,34,25 + p49,34,25 + p13,49,25
                    - p13,41,...


p13 -> [13] ... 8 digits --> 9!
p13,34 -> p134 -> [134] ... 7 digits --> 8!
*/ 

/*
  Total numbers which are less than 500 and are divisible by first 3 prime numbers

  Primes = {2, 3, 5}

  N2 -> 500/2 -> 250
  N3 -> 500/3 -> 166
  N5 -> 500/5 -> 100
  N23 -> 500/6 -> 83
  N25 -> 500/10 -> 50
  N35 -> 500/15 -> 33
  N235 -> 500/30 -> 18

  250 + 166 + 100
  - 83 - 50 - 33
  + 18



*/ 