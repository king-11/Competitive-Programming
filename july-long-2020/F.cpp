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
#define X 1000000009
#define le(x) scanf("%lld", &x)
#define lle(x, y) scanf("%lld %lld", &x, &y)
#define print(x) printf("%lld ", x)
#define println(x) printf("%lld\n", x)
using namespace std;

unsigned nextPowerOf2(unsigned v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t;
    scanf("%lld", &t);
    while (t--)
    {
        int n, x;
        lle(n, x);

        vector<pii> v1;
        v1.reserve(n + 1);

        int y;
        rep(i, n)
        {
            le(y);
            v1.pb({y, 0});
        }

        sort(all(v1));
        int sum = 0;
        rep(i, n)
        {
            int count = 0;
            if (x < v1[i].f)
            {
                int y = nextPowerOf2(v1[i].f / x);
                if (y * x < v1[i].f)
                {
                    y *= 2;
                }
                count = log2(y);
                sum += count;
                x *= y;
            }

            if (x <= 2 * v1[i].f)
            {
                v1[i].s = 1;
                sum++;
                x = 2 * v1[i].f;
            }
        }

        tr(a, v1)
        {
            if (!a.s)
                sum++;
        }

        println(sum);
    }
}
