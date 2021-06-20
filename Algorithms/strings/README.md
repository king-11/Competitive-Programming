# String Algorithms

## Naive Searching

go at each index compare with pattern if they are same do something. The time complexity for this algorithm is O(n*m) and space complexity if O(1)

## Rolling Hash

Rolling hash is a method to generated consecutive hashes using previous value it is a form of DP some might say and saves us time to generate hash from O(N*M) to just O(N).

Let B be the base for upper and lowecase alphabets we use `53` and for only one type use `31`.A hash can be defined as below which will be unique for each substring of length m.

`H[i] = s[0]*B^(m-1)+s1[1]*B^(m-2)......+s1[m]`

The dynamic programming formula for hash is a follows

`H[i] = (H[i-1] - s[i-1]*B^(m-1))*B + s[i]`

But this can go out of bounds very easily thats why we have modulo with a large prime number something like `1e9+9` to ensure that it stays in range. A that causes collisions.

## Rabin Karp

Rabin Karp uses a rolling hash to compare values of hash for a substring for original text and the hash of pattern. if there is a match then we compare character by character. The time complexity of rabin karp is also O(n*m) since we have to compare if hash always comes out same

```cpp
// i = m; i < n; i++
E = binary_expo(B,m-1);
ht = modulo(ht - modulo(text[i-m] * E, MOD), MOD);
ht = modulo(ht * B, MOD);
ht = modulo(ht + text[i], MOD);
```

## Knuth Mortis Pratt

The idea behind KMP is to find longest length of equal proper prefix and suffix for each of the prefix of initial string. This is done using a failure function. The failure function stores the length of longest match it has still that index. F[0] is obviously 0. For succeding values we again look back to DP.

At some point a partial match up to say the prefix (A B A B A) we also have a partial match up to the prefixes (A B A), and (A). Hence F[i] contains information not only about the largest next partial match for the string under index i but also about every partial match of it. F[i] is the first best partial match, F[F[i]] – is the second best, F[F[F[i]]] – the third, and so on. 

Using this information we can calculate F[i] if we know the values F[k] for all k < i

```cpp
// i = 1; i <= m; i++
j = F[i-1];
while(true) {
	// pattern[j] is last character which F[i-1] was not able to match
	if(pattern[i-1] == pattern[j]){
		F[i] = j+1;
		break;
	}

	j = F[j];
	if(j == 0) break;
}
```

The best next partial match of string i will be the largest partial match of string i – 1 whose character that “expands” it is equal to the last character of string i. This is what we are doing using the `if` check and if that's not true we move over to the next best partail match.

```cpp
if(text[i] == pattern[j]){
  i++;
  j++;
  if(j == m) // we have a match
}
else if (j > 0) j = failure[j];
else i++;
```

## Z Function

Z function is basically an array. Z[i] stores the largest prefix of S[i,] which is also a prefix of S. The basic idea can be implemented in O(n*n) by just loop for each of the position and comparing.

>Z[0] doesn't matter can be initialized to 0 or anything

```cpp
for(int i = 1; i < n; i++){
	while(i + z[i] < n && s[z[i]] == s[z[i]+i])
		++z[i];
}
```

We can do better this time using two pointer approach. where we store two pointers `l,r` which are the longest rightmost segment match till now. `r` can be seen as till where we have scanned. 

For each index we see
- If index lies withing `r` then it can either be its previous value or some value less than it or greater. We may sound absurb but that helps. 
	- If `i+z[i-l]` is not beyond `r` then we can just assign the value else we initalize it with `min(z[i-l],r-i+1)` and use our olf O(n*n) method
- if that doesn't lie in box we simply use the O(n*n) algorithm which will move the `r` pointer to some new position if there was atleast some match.
- Finally we update `l,r` to a new value if `i + (z[i]-1) > r` `l` becomes i and `r` becomes `i+z[i]-1`

```cpp
if(i <= r){
  z[i] = min(r-i+1,z[i-l]);
}
while(i+z[i] < n && s1[z[i]] == s1[i+z[i]])
    ++z[i];
if (i + z[i] - 1 > r)
  l = i, r = i + z[i] - 1;
```

>How can we say that this is a O(n) time algo as we can see a while loop still exists. We can see that at max the `r` can move to `n` and similary `n` and both move independent of each other. So we can say that max time complexity is O(n).

### String searching using Z function

define a new string `s = p + $ + t` and calculate z function for it which can be done in O(n+m) time. now we will check if from `m+1` (0 based indexing) onwards we find a match for prefix length of `p` which means we have a match in `t` with `p` because that's the prefix of `s`. we can then have our matches