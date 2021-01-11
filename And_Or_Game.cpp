/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-10-14 14:56:31
 * @ Modified by: Target_X
 * @ Modified time: 2021-01-09 00:10:41
 * @ Description:
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

using namespace std;

// available snippets
// phi, seive, exponentiation, gcd, extended euclid, dfs, path lca, factorization
// kmp search, segtree, dsu, ordered set, power2

using namespace std;
using namespace __gnu_pbds;

const int N = 3e5 + 11;

int32_t main()
{
    SpeedForce;

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vi v1(n), v2(m);
        tr(a, v1)
        {
            cin >> a;
        }

        tr(a, v2)
        {
            cin >> a;
        }

        stack<int> s1;
        s1.push(0);
        unordered_set<int> m1;

        int temp;
        while (!(s1.empty()))
        {
            temp = s1.top();
            s1.pop();
            tr(a, v1)
            {
                int val = (a | temp);
                auto it = m1.find(val);
                m1.insert(val);
                if (it == m1.end())
                    s1.push(val);
            }
            tr(a, v2)
            {
                int val = (a & temp);
                auto it = m1.find(val);
                m1.insert(val);
                if (it == m1.end())
                    s1.push(val);
            }
        }

        println((int)m1.size());
    }
}
