/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-02-08 10:46:34
 * @ Modified by: Target_X
 * @ Modified time: 2021-02-08 10:50:10
 * @ Description: Jai Shree Ram
 */

#include <bits/stdc++.h>
#include <climits>
#include <cstddef>
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

class MinStack {
private:
  stack<pii> s1;
public:
  pii top();
  int minElement();
  void pop();
  void push(int x);
  bool empty();
  size_t size();
};

int MinStack::minElement() {
  return s1.top().s;
}

pii MinStack::top() {
  return s1.top();
}

void MinStack::pop() {
  s1.pop();
}

void MinStack::push(int x) {
  s1.push(mp(x,s1.empty() ? x : min(x,s1.top().s)));
}

bool MinStack::empty() {
  return s1.empty();
}

size_t MinStack::size() {
  return s1.size();
}

class MinQueue {
  MinStack push_stack, pop_stack;
public:
  pii front() {
    if(!pop_stack.empty())
      return pop_stack.top();
    else {
      while(!push_stack.empty()){
        auto [x,minx] = push_stack.top();
        push_stack.pop();
        pop_stack.push(x);
      }
      return pop_stack.top();
    }
  }

  int minElement() {
    if(!pop_stack.empty() && !push_stack.empty())
      return min(pop_stack.minElement(),push_stack.minElement());
    else
      return (pop_stack.empty() ? push_stack.minElement() : pop_stack.minElement());
  }

  bool empty() {
    return pop_stack.empty() && push_stack.empty();
  }

  size_t size() {
    return push_stack.size() + pop_stack.size();
  }

  void push_back(int x){
    push_stack.push(x);
  }

  void pop_front() {
    if(pop_stack.empty()){
      while(!push_stack.empty()){
        auto [x,minx] = push_stack.top();
        push_stack.pop();
        pop_stack.push(x);
      }
    }
    
    pop_stack.pop();
  }
};

void solve() {
  int n;
  cin >> n;
  MinQueue s1;
  while(n--){
    int x;
    cin >> x;
    s1.push_back(x);
  }

  while(!s1.empty()){
    cout << s1.front().f << " " << s1.minElement() << endl;
    s1.pop_front();
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
