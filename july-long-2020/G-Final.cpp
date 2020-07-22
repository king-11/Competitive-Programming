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
#define print(x) printf("%lld ", x)
#define println(x) printf("%lld\n", x)

using namespace std;

// template <typename T>
// void scan(T &x)
// {
//     x = 0;
//     bool neg = 0;
//     register T c = getchar();

//     if (c == '-')
//         neg = 1, c = getchar();

//     while ((c < 48) || (c > 57))
//         c = getchar();

//     for (; c < 48 || c > 57; c = getchar())
//         ;

//     for (; c > 47 && c < 58; c = getchar())
//         x = (x << 3) + (x << 1) + (c & 15);

//     if (neg)
//         x *= -1;
// }

pii greater_pair(pii x, pii y);
void build_tree(vector<pii> &tree, vi &v1, int loc, int left, int right);
pii range_max(vector<pii> &tree, int left, int right, int low, int high, int loc);
pii find_max(vector<pii> &tree, int left, int right, int low, int high, int loc);

int32_t main()
{
    int n, q;
    lle(n, q);

    vi height, taste;
    vector<pii> t1;

    height.assign(n, 0);
    taste.assign(n, 0);
    t1.reserve(2 * n + 1);

    tr(a, height)
    {
        le(a);
    }
    tr(a, taste)
    {
        le(a);
    }
    rep(i, 2 * n)
    {
        t1.pb({-1, INT_MIN});
    }

    // t1.assign((n << 1), {-1, INT_MIN});
    build_tree(t1, height, 0, 0, n - 1);

    while (q--)
    {
        // cout << q << endl
        //      << flush;
        int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        // scan(a);
        // scan(b);
        // scan(c);
        // cout << a << b << c << endl;
        if (a == 1)
        {
            taste[b - 1] = c;
            continue;
        }

        int left = b - 1, right = c - 1;
        bool flag = 1;

        if (left == right)
        {
            println(taste[left]);
            continue;
        }
        if (height[left] <= height[right])
        {
            printf("-1\n");
            continue;
        }

        int step = (right - left) / abs(right - left), vue = left, sum = taste[left];
        while (vue != right)
        {
            pii nuxt = find_max(t1, vue + step, right, 0, n - 1, 0);
            if (nuxt.s > height[vue])
            {
                sum = -1;
                break;
            }
            else if (nuxt.s == height[vue])
            {
                if (vue == left)
                {
                    sum = -1;
                    break;
                }
                sum -= taste[vue];
            }
            sum += taste[nuxt.f];
            vue = nuxt.f;
        }
        println(sum);
    }
    return 0;
}

pii find_max(vector<pii> &tree, int left, int right, int low, int high, int loc)
{
    if (left > right)
    {
        left = left + right - (right = left);
    }
    // left = left > right ? left + right - (right = left) : left;
    return range_max(tree, left, right, low, high, loc);
}

pii range_max(vector<pii> &tree, int left, int right, int low, int high, int loc)
{
    if (left <= low && right >= high)
        return tree[loc];
    else if (left > high || right < low)
        return {-1, INT_MIN};

    int mid = low + (high - low) / 2;

    return greater_pair(range_max(tree, left, right, low, mid, (loc << 1) + 1), range_max(tree, left, right, mid + 1, high, (loc << 1) + 2));
}

void build_tree(vector<pii> &tree, vi &v1, int loc, int left, int right)
{
    if (left == right)
    {
        tree[loc] = {left, v1[left]};
        return;
    }
    int mid = left + (right - left) / 2;

    build_tree(tree, v1, (loc << 1) + 1, left, mid);
    build_tree(tree, v1, (loc << 1) + 2, mid + 1, right);
    tree[loc] = greater_pair(tree[(loc << 1) + 1], tree[(loc << 1) + 2]);
}

pii greater_pair(pii x, pii y)
{

    if (x.f == -1)
        return y;
    else if (y.f == -1)
        return x;
    else if (x.s > y.s)
        return x;

    return y;
}