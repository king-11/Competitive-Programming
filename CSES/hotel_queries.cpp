/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-02-08 10:46:34
 * @ Modified by: Lakshya Singh
 * @ Modified time: 2021-07-01 15:36:36
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

template <class T, class... Args>
void read(T &x, Args&... args)
{
  read(x);
  read(args...);
}

template <class T>
void write(T x)
{
  if (x < 0)
  {
      putchar('-');
      write(-x);
      return;
  }
  if (x > 9)
      write(x / 10);
  putchar(x % 10 + '0');
}

template <class T>
void writei(T x)
{
  write(x);
  putchar(' ');
}

template <class T>
void writeln(T x)
{
  write(x);
  putchar('\n');
}

template <class T, class... Args>
void write(T x, Args... args)
{
  writei(x);
  write(args...);
}

const int N = 3e5 + 11;
#define MOD 1000000007

void solve() {
  int n, q;
  read(n,q);
  vi v1(n);
  tr(a,v1) read(a);

  int blen = sqrt(n + 0.0) + 1;
  vi v2(blen, INT_MIN);
  rep(i,n){
    maxs(v2[i/blen], v1[i]);
  }

  while(q--){
    int r;
    read(r);
    bool val = false;
    rep(i,blen) {
      if(v2[i] < r){
        continue;
      }

      for(int j = (i)*blen; j < n && j < (i+1)*blen; j++){
        if(v1[j] >= r){
          v1[j] -= r;
          writei(j+1);
          val = true;
          break;
        }
      }

      v2[i] = INT_MIN;
      for(int j = (i)*blen; j < n && j < (i+1)*blen; j++){
        maxs(v2[i], v1[j]);
      }

      break;
    }
    if(!val) writei(0);
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
