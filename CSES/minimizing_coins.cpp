/*
* @Author: Lakshya Singh
* @Date:   2021-02-07 12:53:36
* @Last Modified by:   Lakshya Singh
* @Last Modified time: 2021-02-10 11:56:36
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
#define endl "\n"
#define pii pair<int, int>
#define sz(a) int((a).size())
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())
 
#define vi vector<int>
#define vii vector<pii>
#define si set<int>
#define minq priority_queue<int, vector<int>, greater<int>>
#define maxq priority_queue<int, vector<int>, less<int>>
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
 
const int N = 3e6 + 11;
 
int32_t main()
{
    SpeedForce;
    int n, x;
    cin >> n >> x;
    set<int> s1;
    rep(i,n){
        int y;
        cin >> y;
        s1.insert(y);
    }
 
    int dp[x+1];
    repA(i,1,x+1){
        if(s1.find(i) != s1.end()){
            dp[i] = 1;
            // cout << i << endl;
        } else {
            dp[i] = INT_MAX;
            tr(a,s1){
                if(i - a >= 1)
                    dp[i] = min(dp[i],1+dp[i-a]);
                else
                    break;
            }
        }
    }
 
    print(dp[x] != INT_MAX ? dp[x] : -1);
}