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
#define X 1000000009
#define scani(x) scanf("%lld", &x)
#define scani2(x, y) scanf("%lld %lld", &x, &y)
#define scani3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z);
#define print(x) printf("%lld ", x)
#define println(x) printf("%lld\n", x)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

const int N = 3e5 + 11;
int parent[N], answer[N];

int find_set(int n);

int32_t main()
{
     // #ifndef ONLINE_JUDGE
     //      freopen("input.txt", "r", stdin);
     //      freopen("output.txt", "w", stdout);
     // #endif

     SpeedForce;
     int n, m;
     scani2(n, m);

     rep(i, n + 1)
     {
          parent[i] = i;
          answer[i] = 0;
     }

     int l, r, winner;
     while (m--)
     {
          scani3(l, r, winner);
          l--;
          r--;
          for (int v = find_set(l); v <= r; v = find_set(v))
          {
               if (winner == v + 1)
               {
                    v++;
                    continue;
               }

               answer[v] = winner;
               parent[v] = v + 1;
          }
     }

     rep(i, n)
     {
          print(answer[i]);
     }
}

int find_set(int v)
{
     return v == parent[v] ? v : parent[v] = find_set(parent[v]);
}
