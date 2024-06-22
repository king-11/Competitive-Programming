/*
* @Author: Lakshya Singh
* @Date:   2021-07-22 17:07:46
* @Last Modified by:   Lakshya Singh
* @Last Modified time: 2021-07-24 12:38:58
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

template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &a)
{
  in >> a.f >> a.s;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a)
{
  out << a.f << " " << a.s;
  return out;
}
template <typename T, typename T1>
T maxs(T &a, T1 b)
{
  if (b > a)
    a = b;
  return a;
}
template <typename T, typename T1>
T mins(T &a, T1 b)
{
  if (b < a)
    a = b;
  return a;
}

const int N = 3e5 + 11;
#define MOD 1000000007

void solve() {
  int n, x;
  cin >> n >> x;
  vi v1(n);
  tr(a,v1) cin >> a;
  sort(all(v1));

  int store = 1<<n;
  vector<pii> dp(store, {n+1,0});
  dp[0] = {0,x+1};
  for(int b = 1; b < store; b++){
    for(int k = 0; k < n; k++){
      if(b & (1<<k)) {
        auto [val, weight] = dp[b^(1<<k)];
        if(weight + v1[k] <= x){
          weight += v1[k];
        }
        else{
          val++;
          weight = min(v1[k], weight);
        }
        dp[b] = min(dp[b],{val, weight});
      }
    }
  }

  cout << dp[store-1].f;
}

int32_t main() {
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
