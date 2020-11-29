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

template <typename T>
T gcd(T a, T b) { return (b ? __gcd(a, b) : a); }
template <typename T>
T lcm(T a, T b) { return (a * b) / gcd(a, b); }
int mod_neg(int a, int b, int c)
{
     int res;
     if (abs(a - b) < c)
          res = a - b;
     else
          res = (a - b) % c;
     return (res < 0 ? res + c : res);
}
template <typename T>
T extended_euclid(T a, T b, T &x, T &y)
{
     T xx = 0, yy = 1;
     y = 0;
     x = 1;
     while (b)
     {
          T q = a / b, t = b;
          b = a % b;
          a = t;
          t = xx;
          xx = x - q * xx;
          x = t;
          t = yy;
          yy = y - q * yy;
          y = t;
     }
     return a;
}
template <typename T>
T mod_inverse(T a, T n)
{
     T x, y, z = 0;
     T d = extended_euclid(a, n, x, y);
     return (d > 1 ? -1 : mod_neg(x, z, n));
}

using namespace std;

const int N = 3e5 + 11;
vector<string> v1;
int arr[50][50];
int n;

void dfs(int i, int j)
{
     if (arr[i][j] == 1)
          return;

     arr[i][j] = 1;
     if (i - 1 >= 0 && v1[i - 1][j] == '1')
          dfs(i - 1, j);
     if (j - 1 >= 0 && v1[i][j - 1] == '1')
          dfs(i, j - 1);

     return;
}

void targetx()
{
     cin >> n;
     v1.clear();
     rep(i, n)
         rep(j, n)
             arr[i][j] = 0;

     v1.assign(n, string());
     tr(a, v1)
     {
          cin >> a;
     }

     // rep(i, n)
     // {
     //      rep(j, n)
     //      {
     //           cout << (v1[i][j] == '1') << " ";
     //      }
     //      cout << endl;
     // }

     rep(i, n)
     {
          if (v1[i][n - 1] == '1')
               dfs(i, n - 1);
     }

     rep(i, n)
     {
          if (v1[n - 1][i] == '1')
               dfs(n - 1, i);
     }

     rep(i, n)
     {
          rep(j, n)
          {
               if (v1[i][j] == '1' && arr[i][j] != 1)
               {
                    cout << "NO" << endl;
                    return;
               }
          }
     }
     cout << "YES" << endl;
}

int32_t main()
{
     // #ifndef ONLINE_JUDGE
     //      freopen("input.txt", "r", stdin);
     //      freopen("output.txt", "w", stdout);
     // #endif

     SpeedForce;
     int t;
     cin >> t;

     while (t--)
     {
          targetx();
     }
}
