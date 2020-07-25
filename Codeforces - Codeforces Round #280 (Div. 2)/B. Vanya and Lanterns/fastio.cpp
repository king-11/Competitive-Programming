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
     int n, l;
     scani2(n, l);

     vi arr;
     arr.assign(n, 0);
     int flag = 1;
     rep(i, n)
     {
          scani(arr[i]);
     }

     sort(all(arr));

     float maxi = 0;
     rep(i, n - 1)
     {
          maxi = maxi > (arr[i + 1] - arr[i]) ? maxi : arr[i + 1] - arr[i];
     }

     if (maxi < (arr[0] - 0) * 2)
     {
          maxi = arr[0] - 0;
          flag = 0;

          if (maxi < (l - arr[n - 1]))
          {
               maxi = l - arr[n - 1];
          }

          printf("%.10f\n", maxi);
          exit(0);
     }
     else if (maxi < (l - arr[n - 1]) * 2)
     {
          maxi = l - arr[n - 1];
          flag = 0;
     }
     if (flag)
          printf("%.10f\n", maxi / 2.0);
     else
          printf("%.10f\n", maxi);
}