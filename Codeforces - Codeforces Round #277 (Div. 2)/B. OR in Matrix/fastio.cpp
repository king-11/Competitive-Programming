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
     int m, n;
     cin >> m >> n;
     int arr[m][n];
     rep(i, m)
     {
          rep(j, n)
          {
               arr[i][j] = 1;
          }
     }

     vi row, col;
     row.assign(m, 1);
     col.assign(n, 1);
     int input[m][n];
     rep(i, m)
     {
          rep(j, n)
          {
               cin >> input[i][j];
               if (input[i][j] == 0)
               {
                    row[i] = 0;
                    col[j] = 0;
               }
          }
     }

     rep(i, m)
     {
          rep(j, n)
          {
               if (row[i] == 0 || col[j] == 0)
               {
                    arr[i][j] = 0;
               }
          }
     }

     rep(i, m)
     {
          rep(j, n)
          {
               int res = 0;
               rep(il, m) res |= arr[il][j];
               rep(jl, n) res |= arr[i][jl];

               if (res != input[i][j])
               {
                    cout << "NO\n";
                    exit(0);
               }
          }
     }

     cout << "YES\n";
     rep(i, m)
     {
          rep(j, n)
          {
               cout << arr[i][j] << " ";
          }
          cout << endl;
     }
}