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

const int N = 1e9 + 11;
int n, w;
map<int,int> dp[101]; 
vector<pii> values;

int target(int i, int weight){
     if(weight == 0)
          return 0;
     
     if(i == n-1){
          if(weight < values[i].f)
               return 0;
          else
               return values[i].s;
     }

     if(dp[i].find(weight) != dp[i].end())
          return dp[i][weight];
     
     int a = INT_MIN, b = INT_MIN;
     if(values[i].f <= weight)
          a = values[i].s + target(i+1,weight-values[i].f);

     b = target(i+1,weight);
     dp[i][weight] = max(a,b);
     return dp[i][weight];
}

int32_t main()
{
     // #ifndef ONLINE_JUDGE
     //      freopen("input.txt", "r", stdin);
     //      freopen("output.txt", "w", stdout);
     // #endif

     SpeedForce;
     cin >> n >> w;

     values.assign(n,{0,0});
     tr(a,values){
          cin >> a.f >> a.s;
     }

     cout << target(0,w) << endl;
}