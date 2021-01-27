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

int nsum(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        int c = 0, m = 0;

        int x, y;
        rep(i, n)
        {
            cin >> x >> y;
            x = nsum(x);
            y = nsum(y);
            if (x < y)
            {
                m++;
            }
            else if (x > y)
            {
                c++;
            }
            else
            {
                m++;
                c++;
            }
        }

        if (m < c)
        {
            cout << 0 << " " << c << endl;
        }
        else if (c < m)
        {
            cout << 1 << " " << m << endl;
        }
        else
        {
            cout << 2 << " " << m << endl;
        }
    }
}