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
#define X 1000000000
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

unordered_set<int> s1;
void primes(int n)
{
    if (n % 2 == 0)
    {
        s1.insert(2);
        while (n % 2 == 0)
            n /= 2;
    }

    for (int i = 3; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            s1.insert(i);
            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 1)
        s1.insert(n);
}

int32_t main()
{
    SpeedForce;

    int n;
    cin >> n;

    vector<pii> v1;
    v1.reserve(n);
    int x, y;
    rep(i, n)
    {
        cin >> x >> y;
        v1.pb({x, y});
    }
    int a = v1[0].f, b = v1[0].s;
    primes(a);
    primes(b);

    // tr(a, s1)
    // {
    //     cout << a << " ";
    // }
    tr(a, s1)
    {
        int flag = 1;
        tr(b, v1)
        {
            if (b.f % a != 0 && b.s % a != 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            cout << a;
            return 0;
        }
    }
    cout << -1;
}