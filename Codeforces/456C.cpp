/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-10-14 14:56:31
 * @ Modified by: Target_X
 * @ Modified time: 2021-01-29 23:49:54
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

int32_t main()
{
  SpeedForce;
  int n;
  cin >> n;
  vi v1(n);
  tr(a, v1)
  {
    cin >> a;
  }

  sort(all(v1));
  vector<pii> v2;
  v2.reserve(n);
  rep(i, n)
  {
    int count = 1;
    int cur = v1[i];
    while (i < n - 1 && v1[i + 1] == cur)
    {
      count++;
      i++;
    }

    v2.pb({cur, count});
  }

  int n_star = v2.size();
  int dp[n_star + 1];
  dp[0] = 0;
  dp[1] = v2[0].f * v2[0].s;
  repA(i, 2, n_star)
  {
    if (v2[i - 1 - 1].f == v2[i - 1].f - 1)
    {
      dp[i] = max(dp[i - 1], dp[i - 2] + v2[i - 1].f * v2[i - 1].s);
    }
    else
    {
      dp[i] = v2[i - 1].f * v2[i - 1].s + dp[i - 1];
    }
  }

  cout << dp[n_star];
}
