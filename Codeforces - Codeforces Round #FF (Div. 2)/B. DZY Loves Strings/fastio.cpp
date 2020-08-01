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
     string s1;
     cin >> s1;

     int n, k = s1.size();
     cin >> n;
     int max = INT_MIN;

     vi arr;
     arr.assign(26, 0);
     tr(a, arr)
     {
          cin >> a;
          max = max > a ? max : a;
     }

     // cout << s1 << " " << n << endl;
     // tr(a, arr)
     // {
     //      cout << a << " ";
     // }
     int sum = 0;
     rep(i, k)
     {
          int x = s1[i] - 'a';
          // cout << arr[x] << " ";
          sum += (i + 1) * (arr[x]);
     }

     sum += (((n + k) * (n + k + 1)) / 2 - (k * (k + 1)) / 2) * max;
     println(sum);
}