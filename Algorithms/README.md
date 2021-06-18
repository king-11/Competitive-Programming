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


## Non Deterministric Polynomial Time

The class P consists of those problems that are solvable in polynomial time.
More specifically, they are problems that can be solved in time O(n^k) for some
constant k, where n is the size of the input to the problem. Most of the problems
examined in previous chapters are in P.

The class NP consists of those problems that are “verifiable” in polynomial time. If we were somehow given a “certificate” of a solution, then we could verify that the certificate is correct in time polynomial in the size of the input to the problem.

Any problem in P is also in NP, since if a problem is in P then we can solve it
in polynomial time without even being supplied a certificate. We shall formalize this notion later in this chapter, but for now we can believe that P  NP. The open question is whether or not P is a proper subset of NP.

If any NP-complete problem can be solved in polynomial time, then every problem in NP has a polynomial-time algorithm.
