#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long int ll;

pair<ll, ll> max_p(pair<int, int> a, pair<int, int> b)
{

	if (a.first == -1)
	{
		return b;
	}
	else if (b.first == -1)
	{
		return a;
	}
	if (a.second > b.second)
	{
		return a;
	}
	return b;
}

void build_tree(vector<ll> &arr, vector<pair<ll, ll>> &seg_tree, ll l, ll r, ll pos)
{
	if (l == r)
	{
		seg_tree[pos] = {l, arr[l]};
		return;
	}
	ll mid = l + (r - l) / 2;
	build_tree(arr, seg_tree, l, mid, 2 * pos + 1);
	build_tree(arr, seg_tree, mid + 1, r, 2 * pos + 2);
	seg_tree[pos] = max_p(seg_tree[2 * pos + 1], seg_tree[2 * pos + 2]);
}

pair<ll, ll> range_max(ll left, ll right, vector<pair<ll, ll>> &seg_tree, ll low, ll high, ll pos)
{
	if (left <= low && right >= high)
	{
		return seg_tree[pos];
	}
	if (left > high || right < low)
	{
		return {-1, INT_MIN};
	}
	int mid = low + (high - low) / 2;

	return max_p(range_max(left, right, seg_tree, low, mid, pos * 2 + 1), range_max(left, right, seg_tree, mid + 1, high, pos * 2 + 2));
}

pair<ll, ll> max_between(vector<pair<ll, ll>> &seg_tree, ll left, ll right, ll low, ll high, ll pos)
{
	if (left > right)
	{
		ll temp = left;
		left = right;
		right = temp;
	}
	return range_max(left, right, seg_tree, low, high, pos);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, Q;
	cin >> n >> Q;
	vector<ll> den_height;
	for (ll i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		den_height.push_back(x);
	}
	vector<ll> taste;
	for (ll i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		taste.push_back(x);
	}
	vector<pair<ll, ll>> seg_tree;
	for (int i = 0; i < 2 * n; i++)
	{
		seg_tree.push_back({-1, INT_MIN});
	}
	build_tree(den_height, seg_tree, 0, n - 1, 0);

	while (Q--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			taste[b - 1] = c;
		}
		else
		{
			ll src = b - 1;
			ll dest = c - 1;
			bool flag = true;
			if (src == dest)
			{
				cout << taste[src] << endl;
				continue;
			}
			if (den_height[src] <= den_height[dest])
			{
				cout << -1 << endl;
				continue;
			}
			int dir = (dest - src) / abs(dest - src);
			ll curr = src;
			ll next;
			ll total_taste = taste[src];
			while (curr != dest)
			{
				pair<ll, ll> next_peak = max_between(seg_tree, curr + dir, dest, 0, n - 1, 0);
				if (next_peak.second > den_height[curr])
				{
					total_taste = -1;
					break;
				}
				else if (next_peak.second == den_height[curr])
				{
					if (curr == src)
					{
						total_taste = -1;
						break;
					}
					total_taste -= taste[curr];
				}
				total_taste += taste[next_peak.first];
				curr = next_peak.first;
			}
			cout << total_taste << endl;
		}
	}
	return 0;
}