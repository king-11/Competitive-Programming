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

// const int N = 1e5;  // limit for array size
int n, m, parity; // array size
vi t;

template <class T>
void read(T &x)
{
    char ch;
    bool neg = false;
    for (ch = getchar(); !isdigit(ch); ch = getchar())
        neg = ch == '-';
    x = ch - '0';
    for (ch = getchar(); isdigit(ch); ch = getchar())
        (x *= 10) += ch - '0';
    x *= neg ? -1 : 1;
}

template <class T, class... Args>
void read(T &x, Args &... args)
{
    read(x);
    read(args...);
}

template <class T>
void write(T x)
{
    if (x < 0)
    {
        putchar('-');
        write(-x);
        return;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

template <class T>
void writei(T x)
{
    write(x);
    putchar(' ');
}

template <class T>
void writeln(T x)
{
    write(x);
    putchar('\n');
}

template <class T, class... Args>
void write(T x, Args &... args)
{
    writei(x);
    writei(args...);
}

void build()
{ // build the tree
    for (int i = n - 1; i > 0; --i)
    {
        int check = log2(i);
        if (parity != (check & 1))
            t[i] = t[(i << 1)] | t[(i << 1) | 1];
        else
            t[i] = t[(i << 1)] ^ t[(i << 1) | 1];
    }
}

void modify(int p, int value)
{ // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1)
    {
        int check = log2(p);
        if (parity == (check & 1))
            t[p >> 1] = (t[p] | t[p ^ 1]);
        else
            t[p >> 1] = (t[p] ^ t[p ^ 1]);
    }
}

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    SpeedForce;

    read(n, m);
    parity = n & 1;
    n = (1 << n);
    t.assign(2 * n, 0);
    for (int i = 0; i < n; ++i)
    {
        read(t[n + i]);
    }

    build();

    int p, b;
    while (m--)
    {
        read(p, b);
        modify(p - 1, b);
        writeln(t[1]);
    }
}