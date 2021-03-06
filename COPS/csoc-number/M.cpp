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

int isPrime[1000000 + 1];
void sieve()
{
    for (int i = 0; i <= 1000005; ++i)
    {
        isPrime[i] = i;
    }
    isPrime[0] = 0;
    isPrime[1] = 1;
    for (int i = 2; i * i <= 1000005; ++i)
    {
        if (isPrime[i] == i)
        { //Mark all the multiples of i as composite numbers
            for (int j = i * i; j <= 1000005; j += i)
                if (isPrime[j] == j)
                    isPrime[j] = i;
        }
    }
}

int32_t main()
{
    SpeedForce;

    int n;
    cin >> n;
    sieve();

    int final = 1;
    while (n != 1)
    {
        final *= isPrime[n];
        int curr = isPrime[n];
        while (n % curr == 0)
        {
            n /= curr;
        }
    }
    cout << final;
}