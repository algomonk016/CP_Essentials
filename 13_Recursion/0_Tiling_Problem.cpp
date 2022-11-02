/*
Given: 4*n board
Tiles: 1*4
Find number of ways to fill the board using tiles.

Approach
  f(n) = f(vertical tile) + f(horizontal tile)

  if vertically lagaya:
    board size remaining: n-1
    no of ways: 1 + f(n-1)

  if horizontally lagaya:
    board size remaining: n-4
    no of ways: 1 + f(n-4)

  f(n) = f(n-1) + f(n-4)

  base cases:
    n < 4
      no of ways <- 1

fn -> f(n-1) + f(n-4)
*/ 