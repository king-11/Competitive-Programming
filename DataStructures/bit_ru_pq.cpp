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
#include <vector>

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

template <typename T>
class Node {
public:
  T val;
  int height;
  Node *left, *right;
  Node(T x) : val(x), left(NULL), right(NULL), height(0) {};
};

template <typename T>
int getHeight(Node<T> *x){
  return x == NULL ? -1 : x->height;
}

template <typename T>
void setHeight(Node<T> *x){
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
}

template <typename T>
bool isBalanced(Node<T> *x){
  return x == NULL || abs(getHeight(x->left) - getHeight(x->right)) <= 1;
}

// range query & point update
// add needs to be called considering zero based indexing
class BinaryIndexedTree {
  vector<int> bit;
  size_t n;
private:
  void add(int x, int val){
    for(++x; x < n; x += x & -x) {
      bit[x] += val;
    }
  }
public:
  BinaryIndexedTree(int n) {
    this->n = n+1;
    bit.assign(n+1,0);
  }

  BinaryIndexedTree(vector<int> &v1) : BinaryIndexedTree(v1.size()) {
    for(size_t i = 0; i < v1.size(); i++){
      range_add(i,i,v1[i]);
    }
  }

  int query(int x) {
    int sum = 0;
    for(++x; x > 0; x -= x & -x) {
      sum += bit[x];
    }
    return sum;
  }

  void range_add(int l, int r, int x){
    add(l,x);
    add(r+1,x*-1);
  }
};

void solve() {
  int n;
  cin >> n;
  vi v1(n);
  tr(a,v1) cin >> a;
  BinaryIndexedTree b1(v1);


  cout << b1.query(2) << endl;
  cout << b1.query(10) << endl;
  b1.range_add(2, 9, 5);
  cout << b1.query(2) << endl;
  cout << b1.query(10) << endl;
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