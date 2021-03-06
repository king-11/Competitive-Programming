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

bool isPrime[1000009];
void sieve(int N)
{
    for (int i = 0; i <= N; ++i)
    {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= N; ++i)
    {
        if (isPrime[i] == true)
        { //Mark all the multiples of i as composite numbers
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }
}

int32_t main()
{
    SpeedForce;

    int n;
    cin >> n;
    vi v1;
    v1.assign(n, 0);
    tr(a, v1)
    {
        cin >> a;
    }

    sieve(1000005);
    tr(a, v1)
    {
        int x = sqrt(a);
        if (isPrime[x] && x * x == a && x != 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}