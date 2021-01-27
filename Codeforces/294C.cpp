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

int factstore[1001], twopower[1001], mod = 1000000007;

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

int modularExponentiation(int n)
{
    if (twopower[n] == 0)
    {
        twopower[n] = (2 * (modularExponentiation(n - 1) % mod)) % mod;
    }
    return twopower[n];
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
    mem(twopower, 0);

    factstore[0] = 1;
    factstore[1] = 1;
    twopower[0] = 1;

    int n, m;
    cin >> n >> m;

    vector<pii> v1;
    v1.reserve(m + 1);

    int start = 0;
    int arr[m];
    rep(i, m)
    {
        cin >> arr[i];
    }
    sort(arr, arr + m);

    rep(i, m)
    {
        int x = arr[i];
        v1.pb({start, x});
        start = x;
    }
    v1.pb({start, n + 1});

    int top = factorial(n - m), bottom = 1;
    rep(i, m + 1)
    {
        int to;
        to = v1[i].s - v1[i].f - 1;

        if (to <= 0)
            continue;

        bottom = (bottom * factorial(to)) % mod;

        if (i != 0 && i != m)
            top = (top * modularExponentiation(to - 1)) % mod;
    }

    bottom = modInverse(bottom, mod);
    int answer = (bottom * top) % mod;
    cout << answer;
}