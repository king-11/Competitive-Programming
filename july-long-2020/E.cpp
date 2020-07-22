#include <bits/stdc++.h>

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define tr(a, x) for (auto &a : x)
#define all(c) c.begin(), c.end()

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
#define sz(a) int((a).size())
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

#define int long long
#define vi vector<long long>
#define si set<long long>
#define pii pair<int, int>
#define minq priority_queue<int, vector<int>, greater<int>>
#define mem(a, val) memset(a, val, sizeof(a))
#define endl "\n"
#define le(x) scanf("%lld", &x)
#define lle(x, y) scanf("%lld %lld", &x, &y)

#define what_is(x) cerr << #x << " is " << x << endl;
#define X 1000000009

using namespace std;

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    //cout << a[i][j] << " \n"[j == m];

    int t;
    scanf("%lld", &t);
    while (t--)
    {
        int n;
        scanf("%lld", &n);
        vi a1, b1;
        a1.assign(n, 0);
        b1.assign(n, 0);

        unordered_map<int, int> count, m2, m3;
        tr(x, a1)
        {
            le(x);
            count[x]++;
        }
        tr(x, b1)
        {
            le(x);
            count[x]++;
        }

        int flag = 0;
        tr(a, count)
        {
            if (a.s & 1)
            {
                flag = 1;
                break;
            }

            m2[a.f] = (a.s) / 2;
        }
        if (flag)
        {
            printf("-1\n");
            continue;
        }

        vi a2, b2;
        a2.reserve(n + 1);
        b2.reserve(n + 1);

        m3 = m2;
        tr(a, a1)
        {
            if (m3[a])
            {
                m3[a]--;
                continue;
            }

            a2.eb(a);
        }

        m3 = m2;
        tr(a, b1)
        {
            if (m3[a])
            {
                m3[a]--;
                continue;
            }

            b2.eb(a);
        }

        sort(all(b2));
        sort(all(a2), greater<int>());
        if (a2.size() != b2.size())
        {
            printf("-1\n");
            continue;
        }

        int ni = min(*min_element(all(a1)), *min_element(all(b1)));
        ni *= 2;
        int size = a2.size();

        int sum = 0;
        rep(i, 0, size)
        {
            sum += min(ni, min(a2[i], b2[i]));
        }
        printf("%lld\n", sum);
    }
}
