#include <iostream>
#include <stack>
#include <vector>
#define M (L + R) / 2
using namespace std;
#define int long long

struct SegmentTree //0-indexed point add update, range sum query
{
    int n;
    vector<int> a;
    void pull(int node) { a[node] = a[node << 1] + a[node << 1 | 1]; }

    void build(vector<int> &arr, int L, int R, int node)
    {
        if (L == R)
        {
            a[node] = arr[L];
            return;
        }
        build(arr, L, M, node << 1);
        build(arr, M + 1, R, node << 1 | 1);
        pull(node);
    }

    void update(int L, int R, int pt, int val, int node)
    {
        if (L == R)
        {
            a[node] = val;
            return;
        }
        if (pt <= M)
            update(L, M, pt, val, node << 1);
        else
            update(M + 1, R, pt, val, (node << 1) + 1);

        pull(node);
    }

    void update(int pt, int val) { update(0, n - 1, pt, val, 1); }

    int query(int L, int R, int left, int right, int node)
    {
        if (L > R || R < left || L > right)
            return 0;
        if (left <= L && R <= right)
            return a[node];
        else
            return query(L, M, left, right, node << 1) + query(M + 1, R, left, right, (node << 1) + 1);
    }
    int query(int left, int right) { return query(0, n - 1, left, right, 1); }

    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        a = vector<int>(4 * (arr.size() + 1));
        build(arr, 0, n - 1, 1);
    }
    SegmentTree() {}
};

struct FlattenedTree
{
    int root, n;
    vector<vector<int>> adj;
    vector<int> entr, ext;

    int timer = 0;
    void dfs(int u, int prev)
    {
        entr[u] = timer++;
        for (const int &v : adj[u])
            if (v != prev)
                dfs(v, u);
        ext[u] = timer++;
    }
    SegmentTree segmentTree;
    FlattenedTree(vector<int> &p, vector<int> &s)
    {
        n = p.size();

        adj = vector<vector<int>>(n);
        for (int u = 0; u < n; u++)
            if (p[u] != -1)
            {
                adj[u].push_back(p[u]);
                adj[p[u]].push_back(u);
            }
            else
                root = u;

        entr = vector<int>(n);
        ext = vector<int>(n);

        dfs(root, -1);

        vector<int> flattenedTree(2 * n);
        for (int u = 0; u < n; u++)
        {
            flattenedTree[entr[u]] = s[u];
            flattenedTree[ext[u]] = -s[u];
        }
        segmentTree = SegmentTree(flattenedTree);
    }
    void update(int pt, int val)
    {
        segmentTree.update(entr[pt], val);
        segmentTree.update(ext[pt], -val);
    }
    bool is_ancestor(int u, int v) //is u an ancestor of v ?
    {
        return entr[u] <= entr[v] && ext[v] <= ext[u];
    }
    int query(int u, int v)
    {
        if (!is_ancestor(u, v))
            return -1;
        else
            return segmentTree.query(entr[u], entr[v]);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> h(n + 1, 0), s(n + 1, 0);
    //0 is a dummy point, to be the "root" of the tree
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    stack<int> travelToRight, travelToLeft;
    vector<int> pRight(n + 1), pLeft(n + 1);
    pRight[0] = pLeft[0] = -1;

    auto iterate = [](int i, stack<int> &traveled, vector<int> &p, vector<int> &h) {
        while (!traveled.empty() && !(h[traveled.top()] > h[i]))
            traveled.pop();
        if (traveled.empty())
            p[i] = 0;
        else
            p[i] = traveled.top();
        traveled.push(i);
    };
    for (int i = 1; i <= n; i++)
        iterate(i, travelToRight, pRight, h);
    for (int i = n; i >= 1; i--)
        iterate(i, travelToLeft, pLeft, h);

    FlattenedTree flat_right(pRight, s), flat_left(pLeft, s);
    while (q--)
    {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1)
        {
            flat_right.update(u, v);
            flat_left.update(u, v);
        }
        else
        {
            if (u <= v)
                cout << flat_right.query(u, v) << '\n';
            else
                cout << flat_left.query(u, v) << '\n';
        }
    }
    cout << flush;
}