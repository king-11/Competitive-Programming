/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-02-08 10:46:34
 * @ Modified by: Target_X
 * @ Modified time: 2021-07-13 13:08:44
 * @ Description: Jai Shree Ram
 */
 
#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <functional>
 
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
  char matrix[n][n];
  rep(i,n){
    rep(j,n){
      cin >> matrix[i][j];
    }
  }
 
  vector<vi> dp(n,vi(n,0));
  dp[n-1][n-1] = 1 && matrix[n-1][n-1] != '*';
  for(int i = n-1; i >= 0; i--){
    for(int j = n-1; j >= 0; j--){
      if(j - 1 >= 0 && matrix[i][j-1] != '*'){
        (dp[i][j-1] += dp[i][j]) %= MOD;
      }
 
      if(i-1 >= 0 && matrix[i-1][j] != '*'){
        (dp[i-1][j] += dp[i][j]) %= MOD;
      }
    }
  }
 
  // rep(i,n){
  //   rep(j,n){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
 
  cout << dp[0][0];
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