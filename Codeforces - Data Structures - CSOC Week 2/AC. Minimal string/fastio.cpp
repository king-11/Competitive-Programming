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
     stack<char> stack;
     string s2 = "";
     int n = s1.size();
     int arr[n + 1];
     arr[n - 1] = s1[n - 1] - 'a';
     arr[n] = INT_MAX;

     repD(i, n - 2, 0)
     {
          arr[i] = min(arr[i + 1], (s1[i] - 'a') * 1LL);
     }

     rep(i, n)
     {
          int val = s1[i] - 'a';
          stack.push(s1[i]);
          if (val > arr[i + 1])
               continue;

          while (!stack.empty() && stack.top() - 'a' <= arr[i + 1])
          {
               s2 += stack.top();
               stack.pop();
          }
     }

     while (!stack.empty())
     {
          s2 += stack.top();
          stack.pop();
     }

     cout << s2;
}
