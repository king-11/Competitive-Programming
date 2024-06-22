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
  int n, m;
  cin >> n >> m;
  vector<vi> v1(n+1);
  rep(i,m) {
    int x, y;
    cin >> x >> y;
    v1[x].pb(y);
    v1[y].pb(x);
  }

  vector<int> parent(n+1, 0);
  vector<int> color(n+1, 0);
  int end = -1;
  function<void(int, int)> dfs = [&](int v, int s) {
    parent[v] = s;
    color[v] = 1;
    tr(a,v1[v]) {
      if(!color[a]){
        dfs(a,v);
      } else if(a != s && color[a] == 1 && end == -1) {
        parent[a] = v;
        end = a;
      }
    }
    color[v] = 2;
  };

  repA(i,1,n) {
    if(!color[i]){
      dfs(i, 0);
    }
  }
  if(end == -1){
    cout << "IMPOSSIBLE";
    return;
  }

  int count = 2;
  ostringstream s1;
  s1 << end << " ";
  int cur = parent[end];
  while(cur != end) {
    s1 << cur << " ";
    count++;
    cur = parent[cur];
  }
  s1 << end;
  cout << count << endl << s1.str();
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