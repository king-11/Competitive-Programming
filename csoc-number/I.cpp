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

using namespace std;

int sum(int n)
{

    if (n <= 0)
        return 0;

    int x = 0;
    x = n % 10 + sum(n / 10);
    return x;
}

int pow(int n, int a)
{
    if (a == 1 || a == 0)
        return n;
    else
        return n * pow(n, a - 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    vi v1;
    v1.reserve(100);
    repA(i, 1, 81)
    {
        int x = b * pow(i, a) + c;
        if (i == sum(x) && x < 1000000000)
        {
            v1.pb(x);
        }
    }
    cout << v1.size() << endl;
    tr(a, v1)
    {
        cout << a << " ";
    }
}