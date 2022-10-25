/*
Chinese Remainder Theorem
  find x such that
    x % 3 = 2
    x % 5 = 3
    x % 7 = 4

    x = (a * 3 * 5) + (b * 3 * 7) + (c * 5 * 7)

      solving separately for all mods
        (a*3*5)%7 + 0 + 0 = 4 
        (a*15)%7 = 4
        (a*1)%7 = 4
        a = 4

        0 + (b*3*7)%5 + 0 = 3
        (b*1)%5 = 3
        b = 3

        0 + 0 + (c*5*7)%3 = 2
        (c*2*1)%3 = 2
        c*2 % 3 = 2
        c = 1

      x = (4*3*5) + (3*3*7) + (1*5*7)
      x = (60) + (63) + (35)
      x = 158

      lcm = 3*5*7 = 105

      all valid x are
        53, 158, 158+105, ..+105, ...
      53 is the minimum positive value of x
*/