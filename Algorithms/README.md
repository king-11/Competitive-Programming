# Theory

## Asymptotic Notation

- Big Thetha: **asymptotically tight bound** Tight upper and lower bound for non negative functions `c1g(n) <= f(n) <= c2g(n)`
- Big O: **asymptotic upper bound** `f(n) <= cg(n)`, thetha subset of Big O
- Big Omega: **asymptotic lower bound** `cg(n) <= f(n)`
- little o: loose asymptotic upper bound
- little omega: loose asymptotic lower bound

## Divide and Conquer

### Master's Theorem

T(n) = aT(n/b) + f(n)

a >= 1, b >= 2

T(n) = theta(n^logb(a)) if f(n) = O(n^(logb(a)-e)), e > 0
T(n) = theta(n^logb(a)*log(n)) if f(n) = theta(n^(logb(a)))
T(n) = theta(f(n)) f(n) = omega(n^(logb(a)+e)), e > 0, af(n/b) <= cf(n) c < 1

Not all cases are covered by master's theorem

**Warning** : (nlogn) is greater than (n) but not polynomially which is a must check for master's

### Substitution Solving

- guess work higher lower bound big omega and smaller upper bound for big o
- changing variables to power of 2
- adding in terms constant or variable as well

### Recurrence Tree

In a recursion tree, each node represents the cost of a single subproblem somewhere in the set of recursive function invocations. We sum the costs within each level of the tree to obtain a set of per-level costs, and then we sum all the per-level costs to determine the total cost of all levels of the recursion.

A recursion tree is best used to generate a good guess, which you can then verify by the substitution method. When using a recursion tree to generate a good guess, you can often tolerate a small amount of “sloppiness,” since you will be verifying your guess later on.

## Non Deterministric Polynomial Time

The class P consists of those problems that are solvable in polynomial time.
More specifically, they are problems that can be solved in time O(n^k) for some
constant k, where n is the size of the input to the problem. Most of the problems
examined in previous chapters are in P.

The class NP consists of those problems that are “verifiable” in polynomial time. If we were somehow given a “certificate” of a solution, then we could verify that the certificate is correct in time polynomial in the size of the input to the problem.

Any problem in P is also in NP, since if a problem is in P then we can solve it
in polynomial time without even being supplied a certificate. We shall formalize this notion later in this chapter, but for now we can believe that P  NP. The open question is whether or not P is a proper subset of NP.

If any NP-complete problem can be solved in polynomial time, then every problem in NP has a polynomial-time algorithm.
