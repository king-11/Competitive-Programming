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
//#define int long long
#define pii pair<int, int>
#define minq priority_queue<int, vector<int>, greater<int>>
#define mem(a, val) memset(a, val, sizeof(a))

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s11, s22;
    cin >> s11 >> s22;
    sort(all(s11));
    sort(all(s22), greater<char>());

    stack<char> end;
    queue<char> start;
    int n = s11.size();
    
    s11 = s11.substr(0,n&1 ? n/2+1:n/2);
    s22 = s22.substr(0,n/2);

    deque<char> s1, s2;
    s1.assign(all(s11));
    s2.assign(all(s22));
    rep(j,n){
        if(!(j&1)){
            if(s1.front() < s2.front()){
                start.push(s1.front());
                s1.pop_front();
            }
            else{
                char c = s1.back();
                end.push(c);
                s1.pop_back();
            }
        }
        else{
            if(s2.front() > s1.front()){
                start.push(s2.front());
                s2.pop_front();
            }
            else{
                char c = s2.back();
                end.push(c);
                s2.pop_back();
            }
        }
    }
    string answer;
    while(!start.empty()){
        answer += start.front();
        start.pop();
    }
    while(!end.empty()){
        answer += end.top();
        end.pop();
    }

    cout << answer;
}

