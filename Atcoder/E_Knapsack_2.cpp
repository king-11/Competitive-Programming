/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-10-14 14:56:31
 * @ Modified by: Target_X
 * @ Modified time: 2020-12-27 16:57:11
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

const int INF = 1e9 + 11;

using namespace std;

// available snippets
// phi, seive, exponentiation, gcd, extended euclid, dfs, path lca, factorization
// kmp search, segtree, dsu, ordered set, power2

using namespace std;
using namespace __gnu_pbds;

const int N = 3e5 + 11;

int32_t main()
{
  SpeedForce;
  int n, w;
  cin >> n >> w;
  vector<pii> v1(n);

  int vsize = 0;
  tr(a, v1)
  {
    cin >> a.f >> a.s;
    vsize += a.s;
  }

  int dp[n + 1][vsize + 1];

  rep(i, n + 1)
      rep(j, vsize + 1)
          dp[i][j] = INF;

  rep(i, n + 1)
  {
    dp[i][0] = 0;
  }

  repA(i, 1, n)
  {
    rep(j, vsize + 1)
    {
      if (v1[i - 1].s > j)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = min(v1[i - 1].f + dp[i - 1][j - v1[i - 1].s], dp[i - 1][j]);
    }
  }

  int ans = INT_MIN;
  rep(i, n + 1)
  {
    rep(j, vsize + 1)
    {
      if (dp[i][j] <= w)
        ans = max(ans, j);
    }
  }

  cout << ans;
}
