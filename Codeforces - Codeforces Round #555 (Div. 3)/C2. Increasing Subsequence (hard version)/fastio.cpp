/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-11-29 18:16:34
 * @ Modified by: Target_X
 * @ Modified time: 2020-11-29 22:12:03
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
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    greater<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

const int N = 3e5 + 11;

int32_t main()
{
     // #ifndef ONLINE_JUDGE
     //      freopen("input.txt", "r", stdin);
     //      freopen("output.txt", "w", stdout);
     // #endif

     SpeedForce;
     int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	string res;
	int l = 0, r = n - 1;
	int lst = 0;
	while (l <= r) {
		vector<pair<int, char>> cur;
		if (lst < a[l]) cur.push_back(make_pair(a[l], 'L'));
		if (lst < a[r]) cur.push_back(make_pair(a[r], 'R'));
		sort(cur.begin(), cur.end());
		if (cur.size() == 2 && cur[0].first != cur[1].first) {
			cur.pop_back();
		}
		if (cur.size() == 1) {
			if (cur[0].second == 'L') {
				res += 'L';
				lst = a[l];
				++l;
			} else {
				res += 'R';
				lst = a[r];
				--r;
			}
		} else if (cur.size() == 2) {
			int cl = 1, cr = 1;
			while (l + cl <= r && a[l + cl] > a[l + cl - 1]) ++cl;
			while (r - cr >= l && a[r - cr] > a[r - cr + 1]) ++cr;
			if (cl > cr) {
				res += string(cl, 'L');
			} else {
				res += string(cr, 'R');
			}
			break;
		} else {
			break;
		}
	}

	cout << res.size() << endl << res << endl;

	return 0;
}
