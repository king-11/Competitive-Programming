#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)
#define tr(a, x) for (auto &a : x)
#define all(c) c.begin(), c.end()

#define lld long long
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
#define sz(a) int((a).size())
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

#define vi vector<lld>
#define si set<lld>
#define endl "\n"
// #define int long long
#define pii pair<int, int>
#define minq priority_queue<int, vector<int>, greater<int>>
#define mem(a, val) memset(a, val, sizeof(a))

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    int c = n & 1 ? 1 : 0;
    n -= n & 1;

    if ((k < n / 2) || (n == 0 && k != 0))
    {
        cout << -1;
        return 0;
    }

    if (n == 0 && k == 0)
    {
        cout << 1;
        return 0;
    }

    int i;
    for (i = 2; i <= n - 1; i += 2)
    {
        cout << i << " " << i + 1 << " ";
        k--;
    }

    for (int j = k;; j += k)
    {
        if (j > i && __gcd(j, j + k) == k)
        {
            cout << j << " " << j + k << " ";
            break;
        }
    }
    if (c)
        cout << 1;
}