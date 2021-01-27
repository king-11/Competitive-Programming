/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-10-16 17:23:48
 * @ Modified by: Target_X
 * @ Modified time: 2020-10-16 23:27:39
 * @ Description:
 */

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)
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
#define vi vector<int>
#define si set<int>
#define endl "\n"
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

void insert(deque<int> &d, int val)
{
     while (!d.empty() && d.back() > val)
          d.pop_back();
     d.push_back(val);
}

void remove(deque<int> &d, int val)
{
     if (!d.empty() && d.front() == val)
          d.pop_front();
}

int32_t main()
{
     // #ifndef ONLINE_JUDGE
     //      freopen("input.txt", "r", stdin);
     //      freopen("output.txt", "w", stdout);
     // #endif

     SpeedForce;
     int n, m, a, b, g, x, y, z;
     cin >> n >> m;
     cin >> a >> b;
     cin >> g >> x >> y >> z;

     vector<vi> v1;
     v1.resize(n);
     vector<deque<int>> d1;
     d1.resize(m);
     rep(i, n)
     {
          v1[i].resize(m);
          rep(j, m)
          {
               v1[i][j] = g;
               g = (g * x + y) % z;
          }
     }

     deque<int> horizontal;
     rep(i, m)
     {
          rep(j, a)
          {
               insert(d1[i], v1[j][i]);
          }
          if (i < b)
               insert(horizontal, d1[i].front());
     }

     int ans = 0;
     ans += horizontal.front();
     repA(i, b, m - 1)
     {
          remove(horizontal, d1[i - b].front());
          insert(horizontal, d1[i].front());
          ans += horizontal.front();
     }

     repA(i, a, n - 1)
     {
          horizontal.clear();
          rep(j, m)
          {
               insert(d1[j], v1[i][j]);
               remove(d1[j], v1[i - a][j]);

               if (j < b)
                    insert(horizontal, d1[j].front());
          }

          ans += horizontal.front();

          repA(j, b, m - 1)
          {
               remove(horizontal, d1[j - b].front());
               insert(horizontal, d1[j].front());
               ans += horizontal.front();
          }
     }
     cout << ans << endl;
}
