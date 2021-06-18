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