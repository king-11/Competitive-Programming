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

template <typename T>
class AVLTree {
private:
  Node<T> *root = NULL;

  Node<T>* _rightRotate(Node<T> *node){
    Node<T>* left = node->left;
    Node<T>* leftRight = left->right;

    node->left = leftRight;
    left->right = node;

    setHeight(node);
    setHeight(left);

    return left;
  }

  Node<T>* _leftRotate(Node<T> *node){
    Node<T>* right = node->right;
    Node<T>* rightLeft = right->left;

    node->right = rightLeft;
    right->left = node;

    setHeight(node);
    setHeight(right);

    return right;
  }

  Node<T>* _repair(Node<T> *node) {
    int hl = getHeight(node->left);
    int hr = getHeight(node->right);

    if(abs(hr-hl) <= 1)
      return node;

    if(hr > hl) {
      bool rightHeavy = getHeight(node->right->right) - getHeight(node->right->left) >= 0;
      if(!rightHeavy) {
        node->right = _rightRotate(node->right);
      }

      node = _leftRotate(node);
    }
    else {
      bool leftHeavy = getHeight(node->left->left) - getHeight(node->left->right) >= 0;
      if(!leftHeavy){
        node->left = _leftRotate(node->left);
      }

      node = _rightRotate(node);
    }

    return node;
  }

  Node<T>* _insert(int x, Node<T> *parent){
    if(parent == NULL){
      return new Node<T>(x);
    }


    if(parent->val > x){
      parent->left = _insert(x, parent->left);
    }
    else if(parent->val < x) {
      parent->right = _insert(x, parent->right);
    }
    else
      return parent;

    setHeight(parent);

    if(!isBalanced(parent)) {
      parent = _repair(parent);
    }

    return parent;
  }

  bool _find(T x, Node<T> *node) {
    if (node == NULL)
      return false;
    else if(node->val > x)
      return _find(x,node->left);
    else if(node->val < x)
      return _find(x,node->right);
    else
      return true;
  }

  void _inOrder(Node<T> *node){
    if(node != NULL){
      _inOrder(node->left);
      cout << node->val << " ";
      _inOrder(node->right);
    }
  }

  Node<T>* _erase(int x, Node<T>* parent){
    if(parent == NULL)
      return parent;

    if (x < parent->val)
      parent->left = _erase(x, parent->left);
    else if (x > parent->val)
      parent->right = _erase(x, parent->right);
    else {
      if(parent->left == NULL && parent->right == NULL)
        return NULL;
      else if(parent->left == NULL){
        Node<T>* temp = parent->right;
        delete parent;
        return temp;
      }
      else if(parent->right == NULL){
        Node<T>* temp = parent->left;
        delete parent;
        return temp;
      }
      
      Node<T>* temp = successor(parent->right);
      parent->val = temp->val;
      parent->right = _erase(temp->val, parent->right);
    }

    setHeight(parent);

    if(!isBalanced(parent)) {
      parent = _repair(parent);
    }

    return parent;
  }

  void _inOrderDelete(Node<T>* node){
    if(node != NULL){
      inOrderDelete(node->left);
      inOrderDelete(node->right);
      delete node;
    }
  }

public:
  void insert(T x) {
    root = _insert(x,root);
  }
  bool find(T x) {
    return _find(x,root);
  }
  void inOrder() {
    return _inOrder(root);
  }
  void erase(T x) {
    root = _erase(x, root);
  }
  Node<T>* successor(Node<T>* node){
    Node<T>* temp = node;
    while(temp && temp->left !=  NULL)
      temp = temp->left;

    return temp;
  }
  ~AVLTree() {
    _inOrderDelete(root);
  }
};

void solve() {
  AVLTree<int> *tree = new AVLTree<int>();
  int n;
  cin >> n;
  vi v1(n);
  rep(i,n){
    cin >> v1[i];
    tree->insert(v1[i]);
  }

  rep(i,n){
    if(i&1){
      tree->erase(v1[i]);
    }
    else {
      tree->inOrder();
      cout << endl;
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