/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-02-08 10:46:34
 * @ Modified by: Target_X
 * @ Modified time: 2021-07-20 23:54:30
 * @ Description: Jai Shree Ram
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <numeric>
#include <ostream>
#include <unordered_set>
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
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
#define sz(a) int((a).size())
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

#define vi vector<int>
#define vii vector<pii>
#define si set<int>
#define usi unordered_set<int>
#define mi map<int, int>
#define umi unordered_map<int, int>
#define minq priority_queue<int, vector<int>, greater<int>>
#define maxq priority_queue<int, vector<int>, less<int>>
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

void solve()
{
  int n;
  cin >> n;
  vi v1(n);
  tr(a,v1) cin >> a;
  int sum = accumulate(all(v1),0LL);

  vector<vector<pii>> dp(n,vector<pii>(n,{0,0}));
  for(int i = n-1; i >= 0; i--){
    for(int j = 0; j < n; j++){
      if(i > j)
        continue;
      if(i == j){
        dp[i][j].f = v1[i];
        dp[i][j].s = -v1[i];
      }
      else{
        dp[i][j].f = max(v1[i]+dp[i+1][j].s,v1[j]+dp[i][j-1].s);
        dp[i][j].s = min(dp[i+1][j].f-v1[i],dp[i][j-1].f-v1[j]);
      }
    }
  }

  cout << (dp[0][n-1].f+sum)/2;
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
