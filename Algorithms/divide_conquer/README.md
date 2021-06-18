# Problems

## Maximum Subarray Sum

Real life example buy stocks at somepoint, we know the updates in future of stock, buy-sell stocks to maximize profit. You are allowed to buy one unit of stock only one time and then sell it at a later date

`arr[i] = price[i] - price[i-1]` ; 2 <= i <= n;

then we just need to find maximum subarray sum from arr[i]

### [Implementation](./max_subarray.cpp)

- keep on dividing into halves
- base case return (left, right, sum)
- combine, we already have only left and only right sums find one which crosses through mid, left'-mid and mid+1-right'
- return the largest among all three

## Strassen Algorithm

Assumption that matrix multiplication takes omega(n^3) is false it is actually o(n^3) and thetha(n^log7) ~= thetha(n^2.81). Strasses multiplication is only valid for square matrices whose order is an exact power of 2.

S1 = B12 - B22
S2 = A11 + A12
S3 = A21 + A22
S4 = B21 - B11
S5 = A11 + A22
S6 = B11 + B22
S7 = A12 - A22
S8 = B21 + B22
S9 = A11 - A21
S10 = B11 + B12

P1 = A11 * S1 = A11 * B12 - A11 * B22;

P2 = S2 * B22 = A11 * B22 - A12 * B22;

P3 = S3 * B11 = A21 * B11 - A22 * B11;

P4 = A22 * S4 = A22 * B21 - A22 * B11;

P5 = S5 * S6 = A11 * B11 - A11 * B22 - A22 * B11 - A22 * B22;

P6 = S7 * S8 = A12 * B21 - A12 * B22 - A22 * B21 - A22 * B22;

P7 = S9 * S10 = A11 * B11 - A11 * B12 - A21 * B11 - A21 * B12;

C11 = P5 + P4 - P2 + P6
C12 = P1 + P5
C21 = P3 + P4
C22 = P5 + P1 - P3 - P7


>When non power of 2 pad with zeroes upto to smallest power of 2 greater than N. n*n to N*N where N < 2*n

>3*3 multiplication if dimesion is odd but divisible by 3. Laderman has 23 mutliplication algo strassen is still faster than them as log2(7) ~= log3(21.8)