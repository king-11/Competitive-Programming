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
#define le(x) scanf("%lld", &x)
#define lle(x, y) scanf("%lld %lld", &x, &y)

#define prints(x) printf("%lld ", x)
#define println(x) printf("%lld\n", x)
using namespace std;

template <typename T>
void scan(T &x)
{
    x = 0;
    bool neg = 0;
    register T c = getchar();

    if (c == '-')
        neg = 1, c = getchar();

    while ((c < 48) || (c > 57))
        c = getchar();

    for (; c < 48 || c > 57; c = getchar())
        ;

    for (; c > 47 && c < 58; c = getchar())
        x = (x << 3) + (x << 1) + (c & 15);

    if (neg)
        x *= -1;
}

template <typename T>
void print(T n)
{
    bool neg = 0;

    if (n < 0)
        n *= -1, neg = 1;

    char snum[65];
    int i = 0;
    do
    {
        snum[i++] = n % 10 + '0';
        n /= 10;
    }

    while (n);
    --i;

    if (neg)
        putchar('-');

    while (i >= 0)
        putchar(snum[i--]);

    putchar('\n');
}

#define scan2(x, y) \
    scan(x);        \
    scan(y)

struct node
{
    int sum = 0;
    vector<int> values;
    vector<int> prefix;
};

vector<int> combine(node *a, node *b)
{
    int sizel = a->values.size(), sizer = b->values.size();
    int ll = a->values[0], lr = a->values[sizel - 1];
    int rl = b->values[0], rr = b->values[sizel - 1];

    if (lr < rl)
    {
        return
    }
}

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n, q;
    scan2(n, q);
    vector<int> arr;
    arr.assign(n, 0);
    tr(a, arr)
    {
        cin >> a;
    }

    node tree[2 * n];
}
