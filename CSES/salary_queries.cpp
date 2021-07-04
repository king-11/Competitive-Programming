/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-02-08 10:46:34
 * @ Modified by: Target_X
 * @ Modified time: 2021-07-03 14:47:47
 * @ Description: Jai Shree Ram
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <functional>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)
#define tr(a, x) for (auto &a : x)
#define all(c) c.begin(), c.end()

// #define int long long
using pii = std::pair<int, int>;
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
#define sz(a) int((a).size())
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

using vi = vector<int>;
using vii = vector<pii>;
using si = set<int>;
using usi = unordered_set<int>;
using mi = map<int, int>;
using umi = unordered_map<int, int>;
using minq = priority_queue<int, vector<int>, greater<int>>;
using maxq = priority_queue<int, vector<int>, less<int>>;
#define endl "\n"
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

// available snippets
// phi, seive, exponentiation, gcd, extended euclid, dfs, path lca,
// prime factor, kmp, segtree, dsu, ordered set, power2, array compression, 2dbit, bit

template<class T> using ods = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

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

template <class T>
void read(T &x)
{
  char ch;
  bool neg = false;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
      neg = ch == '-';
  x = ch - '0';
  for (ch = getchar(); isdigit(ch); ch = getchar())
      (x *= 10) += ch - '0';
  x *= neg ? -1 : 1;
}

template<typename... T>
void read(T&... args) { ((cin >> args), ...);}
template<typename... T>
void writei(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void writeln(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}

const int N = 3e5 + 11;
#define MOD 1000000007

void solve() {
  int n, q;
  read(n,q);

  vi v1(n);
  tr(a,v1) cin >> a;

  vi vals(v1);
  vector<array<int,3>> rec(q);

  rep(i,q){
    char a;
    int b, c;
    read(a,b,c);
    rec[i] = {a == '?',b, c};
    // dynamic array compression
    if(a == '!') vals.push_back(c);
  }

  // sort
  sort(vals.begin(),vals.end());
  // remove
  vals.erase(unique(vals.begin(),vals.end()), vals.end());

  vi bit(vals.size()+1,0);
  function<void(int,int)> add = [&](int i, int val){
    // one based compressed index
    int idx = upper_bound(vals.begin(), vals.end(), i) - vals.begin();
    for(; idx < (int)bit.size(); idx += (idx & -idx)){
      bit[idx] += val;
    }
  };

  function<void()> build = [&](){
    rep(i,n){
      add(v1[i],1);
    }
  };

  function<int(int)> prefix = [&](int i){
    int sum = 0;
    for(; i > 0; i -= (i & -i)){
      sum += bit[i];
    }
    return sum;
  };

  function<int(int,int)> query = [&](int l, int r){
    int r1 = upper_bound(vals.begin(), vals.end(), r) - vals.begin();
    // make sure its l-1 here
    int l1 = upper_bound(vals.begin(), vals.end(), l-1) - vals.begin();
    return prefix(r1) - prefix(l1);
  };

  build();
  tr(a,rec){
    auto [t, k, x] = a;
    if(t){
      writeln(query(k,x));
    }
    else {
      add(v1[k-1],-1);
      v1[k-1] = x;
      add(v1[k-1], 1);
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
