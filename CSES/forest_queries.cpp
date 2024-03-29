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
// prime factor, kmp, segtree, dsu, ordered set, power2, array compression

using namespace std;
using namespace __gnu_pbds;

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
void write(T x, Args &... args)
{
    writei(x);
    writei(args...);
}

const int N = 3e5 + 11;
#define MOD 1000000007

void solve() {
  int n, q;
  cin >> n >> q;
  vector<vi> bit(n+1,vector<int>(n+1,0));

  function<void(int,int,int)> add = [&](int i, int j, int val){
    for(++i; i <= n; i += (i & -i)){
      for(int y = j + 1; y <= n; y += (y & -y)){
        bit[i][y] += val;
      }
    }
  };

  function<int(int,int)> prefix = [&](int i, int j){
    int sum = 0;
    for(++i; i > 0; i -= (i & -i)){
      for(int y = j + 1; y > 0; y -= (y & -y)){
        sum += bit[i][y];
      }
    }
    return sum;
  };

  function<int(int,int,int,int)> query = [&](int i, int j, int i1, int j1){
    return prefix(i1,j1) - prefix(i1,j-1) - prefix(i-1,j1) + prefix(i-1,j-1);
  };

  rep(i,n){
    rep(j,n){
      char x;
      cin >> x;
      if(x == '*'){
        add(j,i,1);
      }
    }
  }

  while(q--){
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    cout  << query(x1-1,y1-1,x2-1,y2-1) << endl;
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
