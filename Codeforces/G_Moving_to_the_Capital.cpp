/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-10-14 14:56:31
 * @ Modified by: Target_X
 * @ Modified time: 2021-01-07 00:23:48
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

using namespace std;

// available snippets
// phi, seive, exponentiation, gcd, extended euclid, dfs, path lca, factorization
// kmp search, segtree, dsu, ordered set, power2

using namespace std;
using namespace __gnu_pbds;

const int N = 2e5 + 11;

vi dijikstra(vi v1[], size_t n)
{
     vi distance;
     distance.assign(n + 1, INT_MAX);
     distance[0] = distance[1] = 0;

     queue<int> q1;
     q1.push(1);
     while (!q1.empty())
     {
          int source = q1.front();
          q1.pop();
          tr(a, v1[source])
          {
               if (distance[a] != INT_MAX)
                    continue;

               distance[a] = distance[source] + 1;
               q1.push(a);
          }
     }

     return distance;
}

void dfs(int source, vi v1[], vi &distance, vi &visited, vi &shorted)
{
     visited[source] = 1;
     shorted[source] = distance[source];
     tr(a, v1[source])
     {
          if ((!visited[a]) && distance[source] < distance[a])
          {
               dfs(a, v1, distance, visited, shorted);
          }

          if (distance[source] < distance[a])
               shorted[source] = min(shorted[source], shorted[a]);
          else
               shorted[source] = min(shorted[source], distance[a]);
     }
}

void solve()
{
     int n, m;
     cin >> n >> m;
     vector<int> v1[n + 1];
     rep(i, m)
     {
          int x, y;
          cin >> x >> y;
          v1[x].pb(y);
     }

     auto distance = dijikstra(v1, n);
     // tr(a, distance)
     // {
     //      cout << a << " ";
     // }

     // cout << endl;
     vi shorted, visited;
     shorted.assign(n + 1, INT_MAX);
     visited.assign(n + 1, 0);
     dfs(1, v1, distance, visited, shorted);
     repA(i, 1, n)
     {
          cout << shorted[i] << " ";
     }

     cout << endl;
}

int32_t main()
{
     SpeedForce;

     int t;
     cin >> t;
     while (t--)
     {
          solve();
     }
}
