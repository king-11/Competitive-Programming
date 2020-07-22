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
using namespace std;

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
        int given;
        scanf("%lld", &given);
        unordered_set<int> r1, c1;
        int x, y;
        int count = 4 * given - 1;
        repA(i, 1, count)
        {
            scanf("%lld %lld", &x, &y);

            if (r1.find(y) != r1.end())
            {
                r1.erase(y);
            }
            else
            {
                r1.insert(y);
            }

            if (c1.find(x) != r1.end())
            {
                c1.erase(x);
            }
            else
            {
                c1.insert(x);
            }
        }

        x = *c1.begin();
        y = *r1.begin();
        printf("%lld %lld\n", x, y);
    }
}