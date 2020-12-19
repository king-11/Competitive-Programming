/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-10-14 14:56:31
 * @ Modified by: Target_X
 * @ Modified time: 2020-12-19 12:46:19
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

const int N = 3e9 + 11;

int32_t main()
{
     // #ifndef ONLINE_JUDGE
     //      freopen("input.txt", "r", stdin);
     //      freopen("output.txt", "w", stdout);
     // #endif

     SpeedForce;
     int t;
     cin >> t;
     while (t--)
     {
          int n;
          cin >> n;
          vector<pii> v1;
          v1.assign(n, {N, 0});

          tr(a, v1)
          {
               cin >> a.f >> a.s;
          }

          v1.pb({N, 0});

          int x = 0,
              sum = 0, remaining = 0, direction = 0;
          for (int i = 0; i < n; i++)
          {
               int nextTic = v1[i + 1].f;
               if (remaining == 0)
               {
                    remaining = abs(x - v1[i].s);
                    direction = x > v1[i].s ? -1 : 1;
               }

               int todo = min(remaining, nextTic - v1[i].f);
               if (v1[i].s >= min(x, x + todo * direction) && v1[i].s <= max(x, x + todo * direction))
                    sum++;

               x += direction * todo;
               remaining -= todo;
          }

          cout << sum << endl;
     }
}
