/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-02-08 10:46:34
 * @ Modified by: Your name
 * @ Modified time: 2021-06-07 01:17:25
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
// phi, seive, exponentiation, gcd, extended euclid, dfs, path lca, factorization
// kmp search, segtree, dsu, ordered set, power2

using namespace std;
using namespace __gnu_pbds;

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

const int N = 3e5 + 11;

void solve(){
  int n, m;
  cin >> n >> m;
  vector<vii> adj_list(n);
  rep(i,m){
    int x, y, z;
    cin >> x >> y >> z;
    adj_list[x].pb({y,z});
    adj_list[y].pb({x,z});
  }
  set<pii> q1;
  vector<pii> min_edge(n, {INT_MAX, -1});
  vi selected(n, 0);
  q1.insert({0, 0});
  int sum = 0;
  rep(i,n){
    pii v = *q1.begin();
    q1.erase(q1.begin());
    selected[v.s] = 1;
    sum += v.f;
    cout << v.s << " " << v.f << endl;
    for(auto x: adj_list[v.s]){
      auto a = q1.find({min_edge[x.f].f, x.f});
      if(selected[x.f])
        continue;

      if(a != q1.end()){
        if(min_edge[x.f].f > x.s){
          q1.erase(a);
          q1.insert({x.s, x.f});
          min_edge[x.f] = {x.s, v.s};
        }
      }
      else {
          q1.insert({x.s, x.f});
          min_edge[x.f] = {x.s, x.f};
      }
    }
  }
  cout << "Minimum Spanning Tree weight is : " << sum << endl;
}

int32_t main()
{
    SpeedForce;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t = 1; //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
