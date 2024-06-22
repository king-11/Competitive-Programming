/*
* @Author: Lakshya Singh
* @Date:   2021-07-22 17:07:46
* @Last Modified by:   Lakshya Singh
* @Last Modified time: 2021-07-24 09:57:28
* @Description: Jai Shree Ram
*/

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
  int n;
  cin >> n;
  vi v1(n+1);
  repA(i,1,n){
    cin >> v1[i];
  }

  function<void()> build_heap = [&]() {
    for(int i = n/2; i > 0; i--){
      if(2*i <= n && v1[2*i] > v1[i]){
          swap(v1[i], v1[2*i]);
      }
      if(2*i+1 <= n && v1[2*i+1] > v1[i]){
          swap(v1[i], v1[2*i+1]);
      }
    }
  };

  function<void(int)> heapify = [&](int idx){
    if(2*idx+1 <= n){
      vector<int> temp{v1[idx], v1[2*idx], v1[2*idx+1]};
      sort(all(temp));
      if(int maxi = temp[2]; maxi == v1[2*idx]){
        swap(v1[idx], v1[2*idx]);
        heapify(2*idx);
      }
      else if(maxi == v1[2*idx+1]){
        swap(v1[idx], v1[2*idx+1]);
        heapify(2*idx+1);
      }
    }
    else if(2*idx <= n && v1[2*idx] > v1[idx]){
        swap(v1[idx], v1[2*idx]);
        heapify(2*idx);
    }
  };

  build_heap();
  int q;
  cin >> q;
  while(q--){
    int k;
    cin >> k;
    if(k != 0) {
      v1.push_back(k);
      n++;
      int idx = (n)/2;
      while(idx > 0){
        heapify(idx);
        idx /=2;
      }
    }
    else if(k == 0) {
      swap(v1[1], v1[n]);
      v1.pop_back();
      n--;
      heapify(1);
    }
    cout << v1[1] << endl << flush;
  }
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
