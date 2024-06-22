/*
 * @Author: Lakshya Singh
 * @Date:   2021-07-22 17:07:46
 * @Last Modified by:   Lakshya Singh
 * @Last Modified time: 2021-10-08 21:08:33
 * @Description: Jai Shree Ram
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <functional>
#include <vector>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)
#define tr(a, x) for (auto &a : x)
#define all(c) c.begin(), c.end()

#define int long long
using pii = std::pair<int, int>;
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
#define sz(a) int((a).size())
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

using vi = std::vector<int>;
using vii = std::vector<pii>;
using si = std::set<int>;
using usi = std::unordered_set<int>;
using mi = std::map<int, int>;
using umi = std::unordered_map<int, int>;
using minq = std::priority_queue<int, std::vector<int>, std::greater<int>>;
using maxq = std::priority_queue<int, std::vector<int>, std::less<int>>;
#define endl "\n"
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

// available snippets
// phi, seive, exponentiation, gcd, extended euclid, dfs, path lca,
// prime factor, kmp, segtree, dsu, ordered set, power2, array compression, 2dbit, bit

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ods = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 3e5 + 11;

#define INF (1LL << 61)
#define MOD 1000000007

void solve()
{
  int n, m;
  cin >> n >> m;

  unordered_map<int, int> m1, m2;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    m1[x] = i + 1;
    m2[i + 1] = x;
  }

  int count = 1;
  for (int i = 2; i <= n; i++)
  {
    if (m1[i - 1] > m1[i])
    {
      count++;
    }
  }

  for (int i = 0; i < m; i++)
  {
    int ai, bi;
    cin >> ai >> bi;
    int a = m2[ai], b = m2[bi];

    set<pair<int, int>> s1;
    if (a > 1)
      s1.insert(make_pair(a-1, a));
    if (a < n)
      s1.insert(make_pair(a, a+1));
    if (b > 1)
      s1.insert(make_pair(b-1, b));
    if (b < n)
      s1.insert(make_pair(b, b+1));

    for (auto &x : s1)
    {
      if (m1[x.f] > m1[x.s]) {
        count--;
      }
    }

    m2[ai] = m2[ai] + m2[bi] - (m2[bi] = m2[ai]);
    m1[a] = m1[a] + m1[b] - (m1[b] = m1[a]);

    for (auto &x : s1)
    {
      if (m1[x.f] > m1[x.s]) {
        count++;
      }
    }

    cout << count << endl;
  }
}

int32_t main()
{
  SpeedForce;

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
    // cout << endl;
  }
  return 0;
}
