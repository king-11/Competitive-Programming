/*
* @Author: Lakshya Singh
* @Date:   2021-02-04 14:03:23
* @Last Modified by:   Lakshya Singh
* @Last Modified time: 2021-02-05 10:03:34
*/

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

// available snippets
// phi, seive, exponentiation, gcd, extended euclid, dfs, path lca, factorization
// kmp search, segtree, dsu, ordered set, power2

using namespace std;
using namespace __gnu_pbds;

const int N = 3e5 + 11;

stack<int> q;

int getMax()
{
  return q.top();
}

void add(int new_element)
{
  int temp = new_element;
  if (!q.empty())
    temp = max(new_element, getMax());
  q.push(temp);
}

void remove()
{
  q.pop();
}

int32_t main()
{
  SpeedForce;
  int n;
  cin >> n;
  vi v1(n);
  tr(a, v1)
  {
    cin >> a;
    add(a);
  }

  int count = 0;
  repD(i, n - 1, 0)
  {
    count += getMax() - v1[i];
    remove();
  }

  cout << count;
}
