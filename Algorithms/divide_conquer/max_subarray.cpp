/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-02-08 10:46:34
 * @ Modified by: Target_X
 * @ Modified time: 2021-02-08 10:50:10
 * @ Description: Jai Shree Ram
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

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

void solve() {
  int n;
  cin >> n;
  vi v1(n);
  tr(a,v1) cin >> a;

  function<tuple<int,int,int>(int, int)> divide = [&](int i, int j){
    if(i == j){
      return tuple<int,int,int>(i,j,v1[i]);
    }

    int mid = i + (j-i)/2;
    auto [leftl, leftr, leftmax] = divide(i,mid);
    auto [rightl, rightr, rightmax] = divide(mid+1,j);
    int leftsum = 0, lefti = mid, rightsum = 0, righti = mid+1, sum = 0;
    for(int k = mid; k >= i; k--){
      sum += v1[k];
      if(sum > leftsum){
        leftsum = sum;
        lefti = k;
      }
    }
    sum = 0;
    for(int k = mid+1; k < j; k++){
      sum += v1[k];
      if(sum > rightsum){
        rightsum = sum;
        righti = k;
      }
    }

    if(int maxsum = max(leftmax,max(rightmax,leftsum+rightsum)); maxsum == leftsum+rightsum){
      return tuple<int,int,int>(lefti,righti,leftsum+rightsum);
    }
    else if(maxsum == leftmax){
      return tuple<int,int,int>(leftl,leftr,leftmax);
    }
    
    return tuple<int,int,int>(rightl,rightr,rightmax);
  };

  auto [left, right, sum] = divide(0,n-1);
  cout << left << " " << right << " " << sum;
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
