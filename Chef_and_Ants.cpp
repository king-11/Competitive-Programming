/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-10-14 14:56:31
 * @ Modified by: Target_X
 * @ Modified time: 2021-01-04 16:57:53
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
        int n;
        cin >> n;
        vector<vi> v1(n);
        vector<pii> size(n);
        map<int, vector<pii>> m1;
        int gsum = 0;
        rep(i, n)
        {
            int m;
            cin >> m;
            v1[i].assign(m, 0);
            int left = 0, right = 0;
            rep(j, m)
            {
                cin >> v1[i][j];
                if (v1[i][j] < 0)
                    left++;
                else
                    right++;

                m1[abs(v1[i][j])].pb({i, j});
            }

            size[i] = {left, right};
            gsum += left * right;
        }

        // tr(a, v1)
        // {
        //     tr(b, a)
        //     {
        //         cout << b << " ";
        //     }
        //     cout << endl;
        // }

        auto iterator = m1.begin();
        while (iterator != m1.end())
        {
            if ((*iterator).s.size() == 1)
            {
                iterator++;
                continue;
            }

            auto array = *iterator;
            tr(a, array.s)
            {
                int value = v1[a.f][a.s];
                // cout << value << " ";
                if (value < 0)
                {
                    bool it = binary_search(v1[a.f].begin(), v1[a.f].end(), abs(value));
                    // cout << it << " ";
                    if (it)
                        gsum -= 1;
                    else
                    {
                        int before = a.s;
                        int location = abs(lower_bound(all(v1[a.f]), abs(value)) - v1[a.f].end());
                        int after = size[a.f].s - location;
                        int newsum = before + after - size[a.f].s;
                        gsum += newsum;
                        // cout << after << " ";
                    }
                }
                else
                {
                    bool it = binary_search(v1[a.f].begin(), v1[a.f].end(), (value * -1LL));
                    // cout << it << " ";
                    if (it)
                        gsum += 0;
                    else
                    {
                        int after = size[a.f].s - a.s + (size[a.f].f) - 1;
                        int location = lower_bound(all(v1[a.f]), -1LL * value) - v1[a.f].begin();
                        int before = size[a.f].f - location;
                        int newsum = before + after - size[a.f].f;
                        gsum += newsum;
                        // cout << size[a.f].s << " ";
                    }
                    // cout << gsum << " ";
                }
            }
            // cout << endl;
            gsum += 1;
            iterator++;
        }

        cout << gsum << endl;
    }
}
