#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)
#define tr(a, x) for (auto &a : x)
#define all(c) c.begin(), c.end()

#define lld long long
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
#define sz(a) int((a).size())
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

#define vi vector<lld>
#define si set<lld>
#define endl "\n"
#define int long long
#define pii pair<int, int>
#define minq priority_queue<int, vector<int>, greater<int>>
#define mem(a, val) memset(a, val, sizeof(a))

using namespace std;

int factstore[100007], mod = 1000000007;

int factorial(int n)
{
    if (factstore[n] != 0)
    {
        return factstore[n];
    }

    int sum;
    factstore[n] = ((n % mod) * (factorial(n - 1) % mod)) % mod;
    return factstore[n];
}

int modularExponentiation1(int x, int n, int M)
{
    int result = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
            result = (result * x) % M;
        x = (x * x) % M;
        n = n / 2;
    }
    return result;
}

int modInverse(int A, int M)
{
    return modularExponentiation1(A, M - 2, M);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    mem(factstore, 0);
    factstore[0] = 1;
    factstore[1] = 1;

    int n, m, g;
    cin >> n >> m >> g;
    if (!g)
    {
        if (n == 1 && m == 0)
        {
            cout << 1;
            return 0;
        }
        else if ((n == 0 && m == 1) || (m == 0 && n > 1))
        {
            cout << 0;
            return 0;
        }
    }
    else
    {
        if ((n == 0 && m == 1) || ((n & 1) && m == 0))
        {
            cout << 1;
            return 0;
        }
        else if ((n == 0 && m > 1) || (m == 0 && (!n & 1)))
        {
            cout << 0;
            return 0;
        }
    }

    int sum = 0;
    for (int i = g; i < n; i += 2)
    {
        int top = factorial(n - i + m - 1);
        int bottom = (factorial(n - i) * factorial(m - 1)) % mod;
        bottom = modInverse(bottom, mod);
        sum += (top * bottom) % mod;
        sum %= mod;
    }
    cout << sum;
}