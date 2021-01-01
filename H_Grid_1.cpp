/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-10-14 14:56:31
 * @ Modified by: Target_X
 * @ Modified time: 2020-12-29 15:24:18
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
#define MOD 1000000007

// available snippets
// phi, seive, exponentiation, gcd, extended euclid, dfs, path lca, factorization
// kmp search, segtree, dsu, ordered set, power2

using namespace std;
using namespace __gnu_pbds;

const int N = 3e5 + 11;

int32_t main()
{
     SpeedForce;
     int n, m;
     cin >> n >> m;
     char arr[n][m];

     rep(i, n)
     {
          rep(j, m)
          {
               cin >> arr[i][j];
          }
     }

     vi dp[n];
     tr(a, dp)
     {
          a.assign(m, 0);
     }
     dp[n - 1][m - 1] = 1;

     repD(i, n - 1, 0)
     {
          repD(j, m - 1, 0)
          {
               if (arr[i][j] == '#')
                    continue;

               if (i + 1 <= n - 1)
                    dp[i][j] += dp[i + 1][j];
               if (j + 1 <= m - 1)
                    dp[i][j] += dp[i][j + 1];

               dp[i][j] %= MOD;
          }
     }

     cout << dp[0][0] % MOD;
}
