#include <bits/stdc++.h>

#define task "..."
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
#define le(x) scanf("%lld", &x)
#define lle(x, y) scanf("%lld %lld", &x, &y)
#define print(x) printf("%lld ", x)
#define println(x) printf("%lld\n", x)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

template <typename T>
int sgn(T val)
{
    return (T(0) < val) - (val < T(0));
}

int n;
string s1;
const int N = 1e6 + 11;
class store
{
public:
    int sum;
    int left;
    int right;
    store()
    {
        this->sum = 0;
        this->left = 0;
        this->right = 0;
    }
};

store tree[N << 1];

store combine(store &a, store &b)
{
    store value;
    int change = min(a.left, b.right);
    value.sum = a.sum + b.sum + change;
    value.left = a.left + b.left - change;
    value.right = a.right + b.right - change;

    return value;
}

void build()
{ // build the tree
    for (int i = n - 1; i > 0; --i)
    {
        tree[i] = combine(tree[(i << 1)], tree[(i << 1) | 1]);
    }
}

store query(int l, int r)
{ // sum on interval [l, r)
    store resl, resr;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            resl = combine(resl, tree[l++]);
        if (r & 1)
            resr = combine(tree[--r], resr);
    }
    return combine(resl, resr);
}

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    SpeedForce;

    cin >> s1;
    n = s1.size();
    rep(i, n)
    {
        tree[n + i].sum = 0;
        if (s1[i] == '(')
        {
            tree[n + i].left = 1;
            tree[n + i].right = 0;
        }
        else
        {
            tree[n + i].left = 0;
            tree[n + i].right = 1;
        }
    }

    build();
    int m;
    cin >> m;

    int a, b;
    store ans;
    while (m--)
    {
        cin >> a >> b;
        ans = query(a - 1, b);
        cout << ans.sum * 2 << endl;
    }
}