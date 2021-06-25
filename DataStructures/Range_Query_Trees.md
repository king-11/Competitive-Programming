# Range Query Trees

These are augmented trees which can perform operations like range query, updates, etc. The time complexity is O(log(n)) for all operations. Building of tree usually takes O(nlog(n)).

## Binary Indexed Tree

Binary Indexed Tree or Fenwick Tree or BIT is a tree which can perform range query, range updates, etc. In O(log(n)) time. Tree is based of the idea that an integer can be written in binary form where it can contain at most log(n) set bits.

The array inside of BIT stores frequency for range `[g(i)+1,i]` for one based indexing and for zero based indexing range is `[g(i),i]`.

There are lots of ways to choose the function g, as long as `0≤g(i)≤i` for all i. The clever part of the Fenwick algorithm is, that there it uses a special definition of the function g that can handle both operations in O(logN) time.

- 0 based : g(i) = i & (i+1) 
- 1 based : g(i) = i - (i&-i)

Now, we just need to find a way to iterate over all j's, such that `g(j)≤i≤j`. It is easy to see that we can find all such j's by starting with i and flipping the last unset bit. We will call this operation h(j).

- 0 based: h(j) = j | j+1
- 1 based: h(j) = j + (j&-j)

![binary indexed tree](./binary_indexed_tree.png)

>The function that we can use inside of a BIT should have

### sum

- first, it adds the sum of the range [g(r)+1,r]  (i.e. bit[r]) to the result
- then it jumps to [g(g(r))+1,g(r)] and adds it
- so on until it finally comes to 1

### increase

sums of the ranges [g(j)+1,j] for 1 based and [g(j),j] for 0 based that satisfy the condition `g(j) < i <=j` for 1 based and `g(j) <= i <=j` for 0 based  are increased by delta , that is bit[j] += delta. Therefore we updated all elements in T that corresponds to ranges in with Ai lies.

for this increase jumps from in increasing indices.

### Scaling Tree

we can just update all the values of bit[i] by bit[i]/c

### [Range Query & Point Update](./bit_rq_pu.cpp)

```python
# code is for one based indexing
def sum(r):
	res = 0
	# 1 -> 0 for 0 based
	r += 1
	while(r > 0):
		res += bit[r]
		# g(r)-1 for 0 based
		r = g(r)
	return res
```

```python
def increase(idx, delta):
	# 0 for 0 based
	idx += 1
	while(idx < n):
		bit[idx] += delta
		idx = h(idx)
```

### [Range/Point Update & Point Query](./bit_ru_pq.cpp)

- range_add is called based off `increase` which we call `add` now onwards it increases value by `val` in range [l,r] by making two point updates.
- for point query we have to take prefix sum the usual way i.e. the `sum` function gets us point value only.

```python
def range_add(l, r, val):
	add(l, val)
	add(r+1, -val)

def point_query(x):
	return sum(x)
```

### [Range Update and Range Query](./bit_ru_rq.cpp)

To support both range updates and range queries we will use two BITs namely B1[] and B2[], initialized with zeros. In intialization call in range_add.

For range addition :

```python
def add(b, idx, x):
    while idx <= N:
        b[idx] += x
        idx += idx & -idx

def range_add(l,r,x):
    add(B1, l, x)
    add(B1, r+1, -x)
    add(B2, l, x*(l-1))
    add(B2, r+1, -x*r)

def range_add(l, r, x):
    add(B1, l, x)
    ad(B1, r+1, -x)
    add(B2, l, x*(l-1))
    add(B2, r+1, -x*r)
```

For range query :

```python
def sum(b, idx):
    total = 0
    while idx > 0:
        total += b[idx]
        idx -= idx & -idx
    return total

def prefix_sum(idx):
    return sum(B1, idx)*idx -  sum(B2, idx)

def range_sum(l, r):
    return prefix_sum(r) - prefix_sum(l-1)
```





