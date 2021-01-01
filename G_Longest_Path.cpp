/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-10-14 14:56:31
 * @ Modified by: Target_X
 * @ Modified time: 2020-12-29 11:42:31
 * @ Description:
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)
#define tr(a, x) for (auto &a : x)
#define all(c) c.begin(), c.end()

#define int long long
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
#define sz(a) int((a).size())
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

#define vi vector<int>
#define si set<int>
#define endl "\n"
#define pii pair<int, int>
#define minq priority_queue<int, vector<int>, greater<int>>
#define mem(a, val) memset(a, val, sizeof(a))
#define scani(x) scanf("%lld", &x)
#define scani2(x, y) scanf("%lld %lld", &x, &y)
#define scani3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z);
#define print(x) printf("%lld ", x)
#define println(x) printf("%lld\n", x)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MOD 1000000009

// available snippets
// phi, seive, exponentiation, gcd, extended euclid, dfs, path lca, factorization
// kmp search, segtree, dsu, ordered set, power2

using namespace std;
using namespace __gnu_pbds;

const int N = 3e5 + 11;

int dp[N], visited[N];

int dfs(int sr, vector<int> v1[])
{
    if (visited[sr])
        return dp[sr];

    visited[sr] = 1;
    // cout << sr << " " << flush;
    for (auto x : v1[sr])
    {
        dp[sr] = max(dp[sr], dfs(x, v1) + 1);
    }

    return dp[sr];
}

int32_t main()
{
    SpeedForce;
    int n, m;
    cin >> n >> m;
    vector<int> v1[n + 1];

    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        v1[x].pb(y);
    }

    rep(i, n + 1)
    {
        dp[i] = 0;
        visited[i] = 0;
    }

    int curr = 0;
    repA(i, 1, n)
    {
        curr = max(curr, dfs(i, v1));
    }

    println(curr);
}
