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
     int n;
     scani(n);
     vi arr;
     arr.assign(n, 0);
     rep(i, n)
     {
          scani(arr[i]);
     }

     vi v2(arr);
     sort(all(v2));
     map<int, int> m1;
     for (int i = 0; i < n; i++)
     {
          m1[v2[i]] = i;
     }
     for (int i = 0; i < n; i++)
     {
          arr[i] = m1[arr[i]];
     }
     int L = -1;
     for (int i = 0; i < n; i++)
     {
          if (arr[i] != i)
          {
               L = i;
               break;
          }
     }
     int R = -1;
     for (int i = n - 1; i >= 0; i--)
     {
          if (arr[i] != i)
          {
               R = i;
               break;
          }
     }
     if (L == -1 || R == -1)
     {
          cout << "yes" << endl;
          cout << 1 << " " << 1 << endl;
     }
     else
     {
          reverse(arr.begin() + L, arr.begin() + R + 1);
          int ok = true;
          for (int i = 0; i < n; i++)
          {
               if (arr[i] != i)
               {
                    ok = false;
               }
          }
          if (ok)
          {
               cout << "yes" << endl;
               print(L + 1);
               println(R + 1);
          }
          else
          {
               cout << "no" << endl;
          }
     }
}