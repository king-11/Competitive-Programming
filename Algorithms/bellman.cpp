/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-02-08 10:46:34
 * @ Modified by: Your name
 * @ Modified time: 2021-05-22 21:55:08
 * @ Description: Jai Shree Ram
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

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
#define scani(x) scanf("%lld", &x)
#define scani2(x, y) scanf("%lld %lld", &x, &y)
#define scani3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z);
#define print(x) printf("%lld ", x)
#define println(x) printf("%lld\n", x)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MOD 1000000009

// available snippets
// phi, seive, exponentiation, gcd, extended euclid, dfs, path lca,
// factorization kmp search, segtree, dsu, ordered set, power2

using namespace std;
using namespace __gnu_pbds;

template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &a) {
  in >> a.f >> a.s;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a) {
  out << a.f << " " << a.s;
  return out;
}
template <typename T, typename T1> T maxs(T &a, T1 b) {
  if (b > a)
    a = b;
  return a;
}
template <typename T, typename T1> T mins(T &a, T1 b) {
  if (b < a)
    a = b;
  return a;
}

const int N = 3e5 + 11;

class Edge {
  public:
  int u, v, w;
  Edge() {};
};

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<Edge> edges(m);
  const int INF = 1e9;
  tr(a, edges)
  {
    cin >> a.u >> a.v >> a.w;
  }
  vi distances, parent(n);
  distances.assign(n, INF);
  parent[0] = -1;
  distances[0] = 0;
  int cycle_start = -1;
  rep(i, n)
  {
    bool any = false;
    int x = -1;
    tr(a, edges)
    {
      if(distances[a.v] > distances[a.u] + a.w && distances[a.u] != INF){
        distances[a.v] = distances[a.u] + a.w;
        parent[a.v] = a.u;
        x = a.v;
        any = true;
      }
    }
    if(!any){
      break;
    }
    else if(i == n-1 && x != -1){
      cycle_start = x;
    }
  }
  tr(a,distances){
    cout << a << " ";
  }

  if(cycle_start != -1){
    cout << endl << "Negative Cycle Found!" << endl;
    rep(i,n){
      cycle_start = parent[cycle_start];
    }
    vi cycle;
    cycle.reserve(n);
    cycle.pb(cycle_start);
    int cycle_end = parent[cycle_start];
    while(cycle_end != cycle_start){
      cycle.pb(cycle_end);
      cycle_end = parent[cycle_end];
    }

    reverse(all(cycle));
    tr(a,cycle){
      cout << a << " ";
    }
  }
}

int32_t main() {
  SpeedForce;

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
    // cout << endl;
  }
  return 0;
}
