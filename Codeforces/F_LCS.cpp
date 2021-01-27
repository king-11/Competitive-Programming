/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-10-14 14:56:31
 * @ Modified by: Target_X
 * @ Modified time: 2020-12-28 22:00:55
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

// available snippets
// phi, seive, exponentiation, gcd, extended euclid, dfs, path lca, factorization
// kmp search, segtree, dsu, ordered set, power2

using namespace std;
using namespace __gnu_pbds;

const int N = 3e5 + 11;

int32_t main()
{
    SpeedForce;
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    vector<int> dp[n + 1];
    tr(a, dp)
    {
        a.assign(m + 1, 0);
    }

    rep(i, n)
    {
        rep(j, m)
        {
            if (i == 0 || j == 0)
            {
                if (s[i] == t[j])
                {
                    dp[i][j] = 1;
                }
                else if (j == 0)
                    dp[i][j] = dp[max(0LL, i - 1)][j];
                else
                    dp[i][j] = dp[i][max(0LL, j - 1)];
            }
            else if (s[i] == t[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
        }
    }

    int total = dp[n - 1][m - 1];
    stringstream final;
    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0)
    {
        if (s[i] == t[j])
        {
            final << s[i];
            i--;
            j--;
            total--;
        }
        else if (i == 0)
        {
            if (0 > dp[i][j - 1])
                i--;
            else
                j--;
        }
        else if (j == 0)
        {
            if (dp[i - 1][j] > 0)
                i--;
            else
                j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    string s1 = final.str();
    reverse(all(s1));
    cout << s1;
}
