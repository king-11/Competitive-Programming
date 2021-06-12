#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)
#define tr(a, x) for (auto &a : x)
#define all(c) c.begin(), c.end()

#define int long long
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
#define sz(a) int((a).size())
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

#define vi vector<int>
#define si set<int>
#define endl "\n"
#define pii pair<int, int>
#define minq priority_queue<int, vector<int>, greater<int>>
#define mem(a, val) memset(a, val, sizeof(a))
#define scani(x) scanf("%lld", &x)
#define scani2(x, y) scanf("%lld %lld", &x, &y)
#define scani3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z);
#define print(x) printf("%lld ", x)
#define println(x) printf("%lld\n", x)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MOD 1000000009

using namespace std;

// available snippets
// phi, seive, exponentiation, gcd, extended euclid, dfs, path lca, factorization
// kmp search, segtree, dsu, ordered set, power2

using namespace std;
using namespace __gnu_pbds;

const int N = 3e5 + 11;

int arr[N];

class Node {
  public:
    Node *left = nullptr, *right = nullptr;
    int freq;
    char x;
    Node(int num, char input) : freq(num), x(input) {};
    bool operator >(const Node &node) const {
      return freq > node.freq;
    }
    bool isLeaf() {
      return !(left) && !(right);
    }
};

class myComparator {
  public:
  int operator() (const Node* a, const Node* b) {
    return a->freq > b->freq;
  }
};

void getCodes(Node* root, int val){
  if(root->left) {
    arr[val] = 0;
    getCodes(root->left, val + 1);
  }

  if(root->right) {
    arr[val] = 1;
    getCodes(root->right, val + 1);
  }

  if(root->isLeaf()){
    cout << root->x << " ";
    rep(i,val){
      cout << arr[i];
    }
    cout << endl;
  }
}

void cleanUp(Node* root){
  if(root->left){
    cleanUp(root->left);
  }
  if(root->right){
    cleanUp(root->right);
  }

  delete root;
}

void cleanVector(vector<Node*> &v1){
  tr(a,v1){
    delete a;
  }
}

void solve() {
  int n;
  cin >> n;
  vector<Node*> v1;
  v1.reserve(n + 1);
  rep(i,n){
    char x;
    int freq;
    cin >> x >> freq;
    v1.pb(new Node(freq, x));
  }

  priority_queue<Node *, vector<Node *>, myComparator> q1;
  tr(a,v1){
    q1.push(a);
  }
  // while(!q1.empty()) {
  //   auto a = q1.top();
  //   q1.pop();
  //   cout << a->x << " " << a->freq << endl;
  // }
  // cleanVector(v1);
  while(q1.size() != 1){
    auto a = q1.top();
    q1.pop();
    auto b = q1.top();
    q1.pop();
    // cout << q1.top()->freq << endl;
    int sum = a->freq + b->freq;
    auto z = new Node(sum, '.');
    z->left = a;
    z->right = b;
    q1.push(z);
  }

  auto root = q1.top();
  q1.pop();
  getCodes(root, 0);
  cleanUp(root);
}

int32_t main() {
  SpeedForce;

  int t = 1;
  // cin >> t;
  while(t--) {
    solve();
  }
}
