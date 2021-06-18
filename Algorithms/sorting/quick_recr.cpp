/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-10-14 14:56:31
 * @ Modified by: Target_X
 * @ Modified time: 2021-01-11 10:58:23
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

// template<typename It>
// void quickSort(const It& lower, const It& upper){
//     auto d = upper - lower;
//     if(d < 2)
//         return;
//     auto middle = lower + d / 2;
//     nth_element(lower, middle, upper);

//     quickSort(lower, middle);
//     quickSort(middle + 1, upper);
// }

void quickSort(int i, int j, vi &v1)
{
    int size = j - i + 1;
    if (size < 2)
        return;

    // int mid = (j + i) / 2;
    // v1[mid] = v1[j] + v1[mid] - (v1[j] = v1[mid]);
    // int curr = (i - 1);
    // repA(curi, i, j - 1)
    // {
    //     if (v1[curi] < v1[j])
    //     {
    //         curr++;
    //         v1[curr] = v1[curr] + v1[curi] - (v1[curi] = v1[curr]);
    //     }
    // }

    // v1[curr + 1] = v1[curr + 1] + v1[j] - (v1[j] = v1[curr + 1]);
    // quickSort(i, curr, v1);
    // quickSort(curr + 2, j, v1);

    while (i < j)
    {
        int mid = (j + i) / 2;
        v1[mid] = v1[j] + v1[mid] - (v1[j] = v1[mid]);
        int curr = (i - 1);
        repA(curi, i, j - 1)
        {
            if (v1[curi] < v1[j])
            {
                curr++;
                v1[curr] = v1[curr] + v1[curi] - (v1[curi] = v1[curr]);
            }
        }

        curr++;
        v1[curr] = v1[curr] + v1[j] - (v1[j] = v1[curr]);

        if (curr - i < j - curr)
        {
            quickSort(i, curr - 1, v1);
            i = curr + 1;
        }
        else
        {
            quickSort(curr + 1, j, v1);
            j = mid - 1;
        }
    }
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
    }

    // quickSort(all(v1));
    quickSort(0, n - 1, v1);
    cout << "Sorted Array of Numbers : " << endl;
    tr(a, v1)
    {
        cout << a << " ";
    }
}
