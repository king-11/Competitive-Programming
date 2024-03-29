/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-02-08 10:46:34
 * @ Modified by: Target_X
 * @ Modified time: 2021-02-08 10:50:10
 * @ Description: Jai Shree Ram
 */

#include <bits/stdc++.h>
#include <cstddef>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <sstream>

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
  Node *back, *front;
  Node(T x) : val(x), back(NULL), front(NULL) {};
  Node(T x, Node * front, Node* back) : val(x), front(front), back(back) {};
};

template <typename T>
class DeQueue {
private:
  Node<T>* HEAD = NULL, * TAIL = NULL;
  size_t size_val = 0;
public:
  void push_back(T x);
  void push_front(T x);
  void pop_back();
  void pop_front();
  T front();
  T back();
  bool empty();
  size_t size();
};

template <typename T>
void DeQueue<T>::push_back(T x) {
  Node<T>* temp = new Node<T>(x,TAIL,NULL);

  this->size_val++;

  if(TAIL == NULL){
    HEAD = TAIL = temp;
    return;
  }

  TAIL->back = temp;
  TAIL = temp;
}

template <typename T>
void DeQueue<T>::push_front(T x) {
  Node<T>* temp = new Node<T>(x,NULL,HEAD);

  this->size_val++;

  if(HEAD == NULL){
    HEAD = TAIL = temp;
    return;
  }

  HEAD->front = temp;
  HEAD = temp;
}

template<typename T>
void DeQueue<T>::pop_front() {
  if(HEAD == NULL)
    return;

  Node<T>* temp = HEAD;

  HEAD = HEAD->back;
  if(HEAD == NULL)
    TAIL = NULL;

  delete temp;
  
  this->size_val--;
}

template<typename T>
void DeQueue<T>::pop_back() {
  if(TAIL == NULL)
    return;

  Node<T>* temp = TAIL;

  TAIL = TAIL->front;
  if(TAIL == NULL)
    TAIL = NULL;

  delete temp;
  
  this->size_val--;
}

template<typename T>
T DeQueue<T>::front() {
  return this->HEAD->val;
}

template <typename T>
T DeQueue<T>::back() {
  return this->TAIL->val;
}

template <typename T>
bool DeQueue<T>::empty() {
  return (this->size() == 0);
}

template<typename T>
size_t DeQueue<T>::size() {
  return this->size_val;
}

void solve() {
  int n;
  cin >> n;
  DeQueue<int> q1;
  rep(i,n){
    int x;
    cin >> x;
    // cout << x << " ";
    if(i&1){
      q1.push_front(x);
  
    }
    else{
      q1.push_back(x);
  
    }
  }

  while(!q1.empty()){
    auto x = q1.front();
    q1.pop_front();
    cout << x << " ";
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
