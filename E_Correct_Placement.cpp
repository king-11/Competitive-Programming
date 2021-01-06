/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-10-14 14:56:31
 * @ Modified by: Target_X
 * @ Modified time: 2021-01-06 18:54:20
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

struct man
{
    int h, w, id;
};

bool operator<(const man &a, const man &b)
{
    return tie(a.h, a.w, a.id) < tie(b.h, b.w, b.id);
}

struct my_min
{
    pii mn1, mn2;
};

vector<pair<int, my_min>> createPrefMins(const vector<man> &a)
{
    vector<pair<int, my_min>> prefMin;
    my_min curMin{pii(INT_MAX, -1), pii(INT_MAX, -1)};
    for (auto x : a)
    {
        if (x.w < curMin.mn1.first)
        {
            curMin.mn2 = curMin.mn1;
            curMin.mn1 = pii(x.w, x.id);
        }
        else
        {
            curMin.mn2 = min(curMin.mn2, pii(x.w, x.id));
        }
        prefMin.emplace_back(x.h, curMin);
    }
    return prefMin;
}

int findAny(const vector<pair<int, my_min>> &mins, int h, int w, int id)
{
    int l = -1, r = (int)mins.size();
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (mins[m].first < h)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    if (l == -1)
    {
        return -1;
    }

    auto mn1 = mins[l].second.mn1;
    auto mn2 = mins[l].second.mn2;
    if (mn1.second != id)
    {
        return mn1.first < w ? mn1.second + 1 : -1;
    }
    return mn2.first < w ? mn2.second + 1 : -1;
}

void solve()
{
    int n;
    cin >> n;
    vector<man> hor, ver;
    vector<pii> a;
    for (int i = 0; i < n; i++)
    {
        int h, w;
        cin >> h >> w;
        hor.push_back({h, w, i});
        ver.push_back({w, h, i});
        a.emplace_back(h, w);
    }

    sort(hor.begin(), hor.end());
    sort(ver.begin(), ver.end());

    auto horMins = createPrefMins(hor);
    auto verMins = createPrefMins(ver);

    for (int i = 0; i < n; i++)
    {
        auto [h, w] = a[i];
        int id = findAny(horMins, h, w, i);
        if (id == -1)
        {
            id = findAny(verMins, h, w, i);
        }
        cout << id << " ";
    }
    cout << endl;
}

int32_t main()
{
    int tests;
    cin >> tests;
    while (tests-- > 0)
    {
        solve();
    }
    return 0;
}
