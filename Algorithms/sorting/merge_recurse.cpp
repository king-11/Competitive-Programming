/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-10-14 14:56:31
 * @ Modified by: Target_X
 * @ Modified time: 2021-01-06 12:24:20
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

void merge(int start, int end, vi &arr)
{
    int mid = (start + end) / 2, size = (end - start + 1);
    int i = start, j = mid + 1, curr = 0;
    vi v1(size);

    while (i <= mid && j <= end)
    {
        if (arr[i] > arr[j])
            v1[curr++] = arr[j++];
        else if (arr[i] <= arr[j])
            v1[curr++] = arr[i++];
    }

    while(i <= mid)
        v1[curr++] = arr[i++];
    while(j <= end)
        v1[curr++] = arr[j++];


    for (int x = start; x <= end; x++){
        arr[x] = v1[x - start];
    }
}

void mergeSort(int start, int end, vi &arr)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    mergeSort(start, mid, arr);
    mergeSort(mid + 1, end, arr);

    merge(start, end, arr);
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

    mergeSort(0, n - 1, v1);
    cout << "Sorted Array of Numbers : " << endl;
    tr(a,v1){
        cout << a << " ";
    }
}
