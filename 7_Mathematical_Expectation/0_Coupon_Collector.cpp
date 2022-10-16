/*
  Coupon Collector Problem
    A certain brand distributes a coupon a packet of chips. The coupon is chosen randomly from a set of "N" distinct coupons.
    What is the expected number of packets one must buy so you get all "N" distinct coupons.

    or how many throws are needed to get all the faces of N sided dice

    Sol
    it's bernaulli -> as we'll get new coupon (success) or old coupon (failure)
    
    E[xi] -> denotes the no of packs to grad ith new coupon
    E[x] = E[x1 + x2 + ... + x3]
    E[x] = E[x1] + E[x2] + ... + E[x3]

    prob of getting ith new coupon -> avbl new coupon / total coupons = n-(i-1)/n
    we've i-1 distinct coupons, so, avbl new coupons -> n - (i-1)
    
    p = n-i+1/n

    e[xi] = 1/p = n/n-i+1
    e[x] = n/n-1+1 + n/n-1 + n/n-2 + ... + n/n-n+1
         = n(1 + 1/2 + 1/3 + ... + 1/n)
*/ 