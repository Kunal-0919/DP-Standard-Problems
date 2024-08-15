// Good chocolates
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
ll n;
vl arr;
ll dp[1005][1005];
ll f(ll i, ll cnt)
{
    if (cnt == n)
        return 0;
    if (cnt > n || i >= n)
        return -1e9;
    if (dp[i][cnt] != -1)
        return dp[i][cnt];
    ll l = f(i + 1, cnt);
    ll r = f(i, cnt + i + 1) + arr[i];
    return dp[i][cnt] = max(l, r);
}

void solve()
{
    cin >> n;
    arr.assign(n, 0);
    for (auto &x : arr)
        cin >> x;
    memset(dp, -1, sizeof(dp));
    cout << f(0, 0) << endl;
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
