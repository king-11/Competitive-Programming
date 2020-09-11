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
int n;
vector<int> v0, v1, v2;
int dp[N][3];

int dynamic(int i, int x){
     if(dp[i][x] != -1)
          return dp[i][x];
     
     if(x == 0){
          dp[i][x] = max(v1[i]+dynamic(i+1,1),v2[i]+dynamic(i+1,2));
     }
     else if(x == 1){
          dp[i][x] = max(v0[i]+dynamic(i+1,0),v2[i]+dynamic(i+1,2));
     }
     else {
          dp[i][x] = max(v0[i]+dynamic(i+1,0),v1[i]+dynamic(i+1,1));
     }

     return dp[i][x];
}

int32_t main()
{
     // #ifndef ONLINE_JUDGE
     //      freopen("input.txt", "r", stdin);
     //      freopen("output.txt", "w", stdout);
     // #endif

     SpeedForce;
     cin >> n;
     v0.assign(n,0);
     v1.assign(n,0);
     v2.assign(n,0);
     rep(i,n){
          cin >> v0[i] >> v1[i] >> v2[i]; 
          dp[i][0] = dp[i][1] = dp[i][2] = -1;
     }

     dp[n-1][0] = max(v1[n-1],v2[n-1]);
     dp[n-1][1] = max(v0[n-1],v2[n-1]);
     dp[n-1][2] = max(v0[n-1],v1[n-1]);

     int a = dynamic(0,0), b = dynamic(0,1), c = dynamic(0,2);
     cout << max(a,max(b,c)) << endl; 
}