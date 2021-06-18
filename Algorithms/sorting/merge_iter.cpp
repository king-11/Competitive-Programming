/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-10-14 14:56:31
 * @ Modified by: Target_X
 * @ Modified time: 2021-01-06 12:37:34
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
    int n;
    cin >> n;
    vi v1(n);

    tr(a, v1)
    {
        cin >> a;
    }

    for (int i = 1; i < n; i *= 2)
    {
        // cout << 2 * i << endl;
        for (int j = 0; j < n; j += (2 * i))
        {
            int start1 = j;
            int mid = min(start1 + i - 1, n - 1);
            int start2 = mid + 1;
            int end = min(start1 + 2 * i - 1, n - 1);

            vi arr(end-start1+1);

            int curr = 0;
            while (start1 <= mid && start2 <= end)
            {
                if (v1[start1] <= v1[start2])
                    arr[curr++] = v1[start1++];
                else
                    arr[curr++] = v1[start2++];
            }

            while (start1 <= mid)
                arr[curr++] = v1[start1++];
            while (start2 <= end)
                arr[curr++] = v1[start2++];

            for (int x = j; x <= end; x++)
            {
                v1[x] = arr[x - j];
            }

            // tr(a,arr){
            //     cout << a << " ";
            // }
            // cout << endl;
        }
        // cout << endl;
    }

    cout << "Sorted Array of Numbers : " << endl;
    tr(a, v1)
    {
        cout << a << " ";
    }
}
