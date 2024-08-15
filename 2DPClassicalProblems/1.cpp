// jump possibility

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MP make_pair
#define rep(i, a, n) for (ll i = a; i <= n; i++)
#define sq(a) (a) * (a)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define endl '\n'
#define f first
#define s second
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<vector<ll>> vvl;
typedef vector<vector<bool>> vvb;
typedef set<ll> si;
typedef set<ll> sl;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef priority_queue<ll> maxHeap;
typedef priority_queue<ll, vl, greater<ll>> minHeap;
typedef map<ll, ll> mii;
typedef map<string, ll> msi;

void setIO(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    // if (sz(name))
    // {
    // freopen((name + ".in").c_str(), "r", stdin);
    // freopen((name + ".out").c_str(), "w", stdout);
    // }
}

const lld pi = 3.14159265358979323846;
ll mod = 1e9 + 7;

ll n, k, dp[500][5005];
vl arr;

bool f(ll i, ll curr)
{
    if (curr == k)
        return 1;
    if (i >= n)
        return 0;
    if (dp[i][curr] != -1)
        return dp[i][curr];
    ll l = f(i + 1, curr);
    ll r = f(i + 1, curr + arr[i]);
    return dp[i][curr] = l || r;
}
void solve()
{
    cin >> n >> k;
    arr.assign(n, 0);
    for (auto &x : arr)
    {
        cin >> x;
    }
    memset(dp, -1, sizeof(dp));
    bool ans = f(0, 0);
    cout << (ans ? "YES" : "NO") << endl;
}

int main()
{
    setIO();
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
