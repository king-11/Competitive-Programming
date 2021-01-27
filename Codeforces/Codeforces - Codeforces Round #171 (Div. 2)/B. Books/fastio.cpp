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
#define int long long
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

const int N = 3e5 + 11;

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    //      freopen("input.txt", "r", stdin);
    //      freopen("output.txt", "w", stdout);
    // #endif

    SpeedForce;
    int n, t;
    scani2(n, t);
    vi v1;
    v1.assign(n, 0);
    tr(a, v1) {
        scani(a);
    }

    vi v2;
    v2.assign(n, 0);
    pii vals;
    vals ={ -1LL, 0LL };

    int sum = 0;
    rep(i, n) {
        if (v1[i] > t)
            continue;

        vals.f = i;

        while (vals.s < vals.f)
            vals.s++;

        while (vals.s < n && sum + v1[vals.s] <= t) {
            sum += v1[vals.s++];
        }

        v2[i] = vals.s-vals.f;
        sum -= v1[i];
    }
    println(*max_element(all(v2)));
}