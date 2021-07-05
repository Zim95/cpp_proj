Modulo properties:
==================
1. (a+b) % m = [(a%m) + (b%m)]%m

2. (a-b) %m = [(a%m) - (b%m) + m]%m
    e.g.
    a = 8, b = 3, m = 7
    LHS => (a - b) % m = (8-3) % 7 = 5 % 7 = 5
    BUT
    RHS => [(a%m) - (b%m)]%m = [8%7 - 3%7]%7 = [1 - 3] % 7 = -2
    See LHS doesnt match with RHS results,
    So we need to add +m, so our RHS becomes -2 + m = -2 + 7 = 5
    Now, LHS == RHS. Therefore we need to add a +m.

3. (a*b)%m = [(a%m) * (b%m)] % m

4. (a/b)%m = [(a%m) * (b_inv %m)] % m
    Here b_inv = multiplicative modulo inverse
    THIS IS where we will extended euclids algorithm
