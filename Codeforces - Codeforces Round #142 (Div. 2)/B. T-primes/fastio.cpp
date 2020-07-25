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

const int N = 3e6 + 11;

bool isPrime[N + 1];
void sieve()
{
     for (int i = 0; i <= N; ++i)
     {
          isPrime[i] = true;
     }
     isPrime[0] = false;
     isPrime[1] = false;
     for (int i = 2; i <= N; ++i)
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
     // #ifndef ONLINE_JUDGE
     //      freopen("input.txt", "r", stdin);
     //      freopen("output.txt", "w", stdout);
     // #endif
     sieve();
     SpeedForce;
     int n;
     scani(n);
     int x, y;
     rep(i, n)
     {
          scani(x);
          y = sqrt(x);
          if (!isPrime[y])
          {
               printf("NO\n");
               continue;
          }

          if (y * y == x)
               printf("YES\n");
          else
               printf("NO\n");
     }
}