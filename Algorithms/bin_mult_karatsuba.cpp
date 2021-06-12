/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-10-14 14:56:31
 * @ Modified by: Target_X
 * @ Modified time: 2021-01-19 11:15:58
 * @ Description:
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)
#define tr(a, x) for (auto &a : x)
#define all(c) c.begin(), c.end()

#define int long long
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
#define sz(a) int((a).size())
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

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

using namespace std;

// available snippets
// phi, seive, exponentiation, gcd, extended euclid, dfs, path lca, factorization
// kmp search, segtree, dsu, ordered set, power2

using namespace std;
using namespace __gnu_pbds;

const int N = 3e5 + 11;

int convertLengthEqual(string &str1, string &str2)
{
  int len1 = str1.size();
  int len2 = str2.size();
  if (len1 < len2)
  {
    for (int i = 0; i < len2 - len1; i++)
      str1 = '0' + str1;
    return len2;
  }
  else if (len1 > len2)
  {
    for (int i = 0; i < len1 - len2; i++)
      str2 = '0' + str2;
  }
  return len1;
}

string addBitStrings(string first, string second)
{
  string result;

  int length = convertLengthEqual(first, second);
  int carry = 0;

  for (int i = length - 1; i >= 0; i--)
  {
    int firstBit = first[i] - '0';
    int secondBit = second[i] - '0';

    int sum = (firstBit ^ secondBit ^ carry) + '0';
    result.push_back((char)sum);

    carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
  }

  if (carry)
    result.push_back('1');

  reverse(all(result));
  return result;
}

int multiply(string X, string Y)
{

  int n = convertLengthEqual(X, Y);

  if (n == 0)
    return 0;
  if (n == 1)
    return (X[0] - '0') * (Y[0] - '0');

  int fh = n / 2;
  int sh = (n - fh);

  string Xl = X.substr(0, fh);
  string Xr = X.substr(fh, sh);

  string Yl = Y.substr(0, fh);
  string Yr = Y.substr(fh, sh);

  int P1 = multiply(Xl, Yl);
  int P2 = multiply(Xr, Yr);
  int P3 = multiply(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr));

  return P1 * (1 << (2 * sh)) + (P3 - P1 - P2) * (1 << sh) + P2;
}

int32_t main()
{
  SpeedForce;
  string s1, s2;
  cin >> s1 >> s2;
  cout << multiply(s1, s2) << endl;
  return 0;
}
