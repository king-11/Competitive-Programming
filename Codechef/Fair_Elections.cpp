/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-10-14 14:56:31
 * @ Modified by: Target_X
 * @ Modified time: 2021-01-03 18:52:23
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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    SpeedForce;

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vi v1(n), v2(m);
        int sum1 = 0, sum2 = 0;
        tr(a, v1)
        {
            cin >> a;
            sum1 += a;
        }
        tr(a, v2)
        {
            cin >> a;
            sum2 += a;
        }

        // if (sum1 > sum2)
        // {
        //     cout << 0 << endl;
        //     continue;
        // }

        int i = 0;
        sort(all(v1));
        sort(all(v2), greater());
        while (sum1 <= sum2 && i < min(n, m))
        {
            if (v1[i] >= v2[i])
                break;

            v1[i] = v2[i] + v1[i] - (v2[i] = v1[i]);
            sum1 = sum1 + v1[i] - v2[i];
            sum2 = sum2 + v2[i] - v1[i];
            i++;
        }

        if (sum1 <= sum2)
        {
            cout << -1;
        }
        else
        {
            cout << i;
        }
        cout << endl;
    }
}
