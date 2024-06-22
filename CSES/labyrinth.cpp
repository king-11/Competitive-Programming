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
  vector<vector<char>> arr(n, vector<char>(m, '#'));
  vector<vector<bool>> marked(n, vector<bool>(m, false));
  vector<vector<pii>> parent(n, vector<pii>(m, {0, 0}));

  pii start = {-1, -1}, end = {-1, -1};
  rep(i, n)
  {
    rep(j, m)
    {
      cin >> arr[i][j];
      parent[i][j] = {i, j};
      if (arr[i][j] == 'A')
        start = {i, j};
      if (arr[i][j] == 'B')
        end = {i, j};
    }
  }

  queue<pii> q;
  q.push(start);
  vector<pii> moves{{1,0}, {-1,0}, {0,1}, {0,-1}};
  while(!q.empty()){
    pii cur = q.front();
    q.pop();
    if (marked[cur.f][cur.s])
      continue;

    marked[cur.f][cur.s] = true;
    if (arr[cur.f][cur.s] == 'B')
      break;

    rep(i, 4){
      int nx = cur.f + moves[i].f;
      int ny = cur.s + moves[i].s;
      if(nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] != '#' && !marked[nx][ny]){
        parent[nx][ny] = {cur.f, cur.s};
        q.push({nx, ny});
      }
    }
  }


  if (parent[end.f][end.s] == end){
    cout << "NO" << endl;
    return;
  }

  stringstream path;
  pii cur = end;
  while(cur != start) {
    if (parent[cur.f][cur.s].f == cur.f)
      path << (parent[cur.f][cur.s].s < cur.s ? 'R' : 'L');
    else
      path << (parent[cur.f][cur.s].f < cur.f ? 'D' : 'U');
    cur = parent[cur.f][cur.s];
  }

  cout << "YES" << endl;
  string finalpath = path.str();
  reverse(all(finalpath));
  cout << finalpath.size() << endl;
  cout << finalpath << endl;
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
