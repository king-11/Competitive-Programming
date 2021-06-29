/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-02-08 10:46:34
 * @ Modified by: Target_X
 * @ Modified time: 2021-02-08 10:50:10
 * @ Description: Jai Shree Ram
 */

#include <bits/stdc++.h>
#include <cstddef>
#include <cstdint>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <functional>

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

class Node {
public:
  int val;
  Node() : val(INT_MAX) {};
  Node(int x) : val(x) {};
};

Node combine(Node &a, Node &b){
  return Node(min(a.val, b.val));
}

void solve() {
  int n;
  cin >> n;
  Node tree[n << 1];
  for(int i = 0; i < n; ++i) cin >> tree[n+i].val;

  function<void()> build = [&]() {
    // build tree
    for(int i = n - 1; i > 0; --i){
      tree[i] = combine(tree[i << 1], tree[(i << 1) | 1]);
    }
  };

  function<Node(int l, int r)> range_query = [&](int l, int r) {
    // range query consider zero based indexing r is not included
    Node resl, resr;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
      // order important for non communicative combiner
      if(l&1) resl = combine(resl, tree[l++]);
      if(r&1) resr = combine(tree[--r], resr);
    }
    return combine(resl, resr);
  };

  function<void(int idx, Node val)> point_update = [&](int idx, Node val){
    // point update zero based indexing given to tree
    for(tree[idx += n] = val; idx > 1; idx >>= 1){
      tree[idx >> 1] = combine(tree[idx], tree[idx^1]);
    }
  };

  build();
  cout << range_query(2,6).val << endl;
  point_update(2,Node(100));
  point_update(3,Node(15));
  cout << range_query(2,6).val << endl;
  tr(a,tree) if(a.val != INT_MAX) cout << a.val << " ";
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
